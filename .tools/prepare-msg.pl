#!/usr/bin/env -S perl -w
use strict;
use v5.24;
use utf8;
use open qw/:std :utf8/;

my @lines = split /\n/, `git status -s`;
say scalar @lines;

my %emo = (
    tada => q/:tada:/,
    ac   => q/:accept:/,
);
my $tg  = shift;
my $emo = $emo{$tg};

sub gac {
    my ( $n, $msg ) = @_;
    system( ( qw{git add}, $n ) ) == 0 or die "git add $n failed: $?";
    system( ( qw{git commit -m}, qq{$emo $msg}, '-e' ) ) == 0
      or die "git commit $n failed: $?";
    say "Done commit: $n";
    exit 0;
}

sub gissue {
    my ($n) = @_;
    chomp( my $line = qx(git log --oneline -20| grep "$n" | head -n 1) );
    say "gissue n:$n line: $line";
    if ( $line =~ m{:accept: (?:AC )?$n \w+ \(#(\d+)\)} ) {
        return $1;
    }
    elsif ( $line =~ m{:tada: $n \(#(\d+)\)} ) {
        return $1;
    }
}

foreach (@lines) {
    if (/^[\s\w]{2}\s(\S+)/) {
        my $n = $1;
        say "handling $n ...";

        if ( $tg eq 'ac' ) {
            if ( $n =~ m{\A(\w+)/(\w)/main\.(?:cc|rs)\Z} ) {
                my $i = &gissue($1);
                &gac( $n, qq{$1 $2 (#$i)} );
            }
        }
        elsif ( $tg eq 'tada' ) {
            if ( $n =~ m{\A(leetcode/(?:bi)?weekly-contest-\d+\.txt)\Z} ) {
                &gac( $n, $1 );
            }
            if ( $n =~ m{\A(\w+)/(\w)/main\.(?:cc|rs)\Z} ) {
                &gac( $n, "$1 (#)" );
            }
        }
        else {
            die "unknown arg1: $tg";
        }
    }
}
