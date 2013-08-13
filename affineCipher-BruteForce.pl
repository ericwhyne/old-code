#!/usr/bin/perl
# Eric Whyne Jan 2004
# License: GPL
# Description: Complimentary program to affineCipher.pl
use strict;
my ($maxa, $a, $b, $inputfile, @cmd);
if(scalar @ARGV != 2){ die "\n\tUSAGE: $0 <input file> <max a>\n\n\tExample: $0 ciphered.txt 26 | grep -i the\n\n";}
else{ $inputfile = @ARGV[0]; $maxa = @ARGV[1];}
for($a = 1; $a <= $maxa; $a++)
{
	if(gcd($a,26)==1)
	{
		for($b = 0;$b < 26; $b++)
		{#	print "a: $a b: $b ";
			@cmd = ("./affineCipher.pl", $inputfile, $a, $b);
			system(@cmd) == 0 or die "Could not find my other half: affineCipher.pl";
		}
	}
}
exit(0);
sub gcd
{   my $a = shift; my $b = shift;
    if ($b > $a){($a, $b) = ($b , $a);}
    while ($a % $b > 0){($a, $b) = ($b, $a % $b);}
    return $b;
}
