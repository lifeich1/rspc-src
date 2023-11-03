#!/usr/bin/env -S perl -w
use strict;
use v5.24;
use utf8;
use open qw/:std :utf8/;
use Time::HiRes qw(gettimeofday);

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
  if ( length($line) eq 0 ) {
    my ( $s, $us ) = gettimeofday;
    say "fallback to slow search ...";
    chomp( $line = qx(git log --oneline| grep "$n" | head -n 1) );
    my ( $s1, $us1 ) = gettimeofday;
    $us = $us1 - $us;
    $s  = $s1 - $s;
    if ( $us lt 0 ) {
      $us += 1_000_000;
      $s  -= 1;
    }
    my $ms = $s * 1000 + $us / 1000;
    say "cost $ms ms";
  }
  say "gissue n:$n line: $line";
  if ( $line =~ m{:accept: (?:AC )?$n \w+ \(#(\d+)\)} ) {
    return $1;
  }
  elsif ( $line =~ m{:tada: (?:\[\w+\] )?$n \(#(\d+)\)} ) {
    return $1;
  }
}

sub gh_isu_n {
  my ($name) = @_;
  chomp( my $line = qx(gh issue list | grep "CP: $name") );
  if ( $line =~ /\A(\d+)\s/ ) {
    return $1;
  }
  return '';
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
      if ( $n =~ m{\A(\d+)/(\w)/main\.(?:cc|rs)\Z} ) {
        my $sn = &gh_isu_n($1);
        &gac( $n, "$1 (#$sn)" );
      }
      if ( $n =~ m{\A(\D\w+)/(\w)/main\.(?:cc|rs)\Z} ) {
        my $sn = &gh_isu_n($1);
        &gac( $n, "[atcoder] $1 (#sn)" );
      }
      if ( $n =~ m{\A(START\w+)/(\w+)/main\.(?:cc|rs)\Z} ) {
        my $sn = &gh_isu_n($1);
        &gac( $n, "[codechef] $1 (#$sn)" );
      }
    }
    else {
      die "unknown arg1: $tg";
    }
  }
}
