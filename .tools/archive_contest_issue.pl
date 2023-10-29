use v5.30;
use utf8;
use strict;

my $tg = shift;
if ( $tg =~ m{_archive/(\w+)} ) {
    $tg = $1;
}
say STDERR "tg: $tg";

chomp( my $line = qx(git log --oneline -20| grep "$tg" | head -n 1) );
say STDERR "line: $line";
if ( $line =~ m{:accept: (?:AC )?$tg \w+ \(#(\d+)\)} ) {
    say $1;
}
elsif ( $line =~ m{:tada: (?:\[\w+\] )$tg \(#(\d+)\)} ) {
    say $1;
}
