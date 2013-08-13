#!/usr/bin/perl
# Eric Whyne Feb 2004 
# License: GPL
# Description: Counts letter frequency in a text file.
use strict;
my $inputfile;
my $outputtype;
usage() if(scalar @ARGV != 2);
if(@ARGV[0] eq '-f' || @ARGV[0] eq '-a'){}  else{usage();}
$outputtype = @ARGV[0];
$inputfile = @ARGV[1];
my (@plaintext, $i);
open(PLAINTEXT,$inputfile);
while(!eof PLAINTEXT){push @plaintext, getc PLAINTEXT}
close(PLAINTEXT);
@plaintext = reverse grep(/[A-Za-z]/, @plaintext);
my $plength = scalar @plaintext;
my $ptnum;
my @falphabet;
for($i=0;$i< $plength; $i++)
{	
	$ptnum = ord(pop @plaintext);
	if($ptnum >= 65 && $ptnum <= 90){ $ptnum = $ptnum - 65;}
	if($ptnum >= 97 && $ptnum <= 122){ $ptnum = $ptnum - 97;}
	$falphabet[$ptnum]++;
}

if($outputtype eq '-a')
{
	for($i=0;$i<26; $i++)
	{
		print chr($i+65) . "\t\t\t" . @falphabet[$i] . "\t\t" . @falphabet[$i]/$plength . "\n"; 
	}
}
# my $tallest; #ref to Zim.Invader, die(hyu-maan);
else {
	my %hash;
	my @sortedarray;
	@sortedarray = @falphabet;
	@hash{@sortedarray} = @sortedarray;
	@sortedarray = keys %hash; #last two lines get rid of repeat values in @sortedarray - urk
	@sortedarray= sort {$a <=> $b} @sortedarray;
	@sortedarray = reverse @sortedarray;
	foreach(@sortedarray)
	{ 
		for($i=0;$i<26;$i++)
		{
			if($falphabet[$i] == $_) { print chr($i+65) . "\t\t\t" . $_ . "\t\t" . $_/$plength . "\n" ; }
		}
	}
}
exit(0);
sub usage { die "\nUSAGE: $0 <-f or -a> <input file>\n\n\t-f\t Sort output by frequency.\n\t-a\t Sort alphabetically.\n\n\t Output: Letter\tTotal\tFrequency\n\n";}
