use v5.30;
use utf8;
use strict;

my $tg = shift;
if ( $tg =~ m{_archive/(\w+)} ) {
  $tg = $1;
}
say STDERR "tg: $tg";

my @line = split /\n/, qx(git log --oneline -20| grep "$tg" | head);
foreach (@line) {
  say STDERR "line: $_";
  if (m{:accept: (?:AC )?$tg \w+ \(#(\d+)\)}) {
    say $1;
    last;
  }
  elsif (m{:tada: (?:\[\w+\] )?$tg \(#(\d+)\)}) {
    say $1;
    last;
  }
}
