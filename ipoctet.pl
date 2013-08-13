#!/usr/bin/perl
# OctetIPs.pl
# Eric Whyne 2004 
# License: GPL
# Description: Breaks a file of IP addresses into their octets.
use strict;
my $inputfile;
my $display;
usage() if(scalar @ARGV != 2);
$inputfile = @ARGV[0];
$display = @ARGV[1];
my @ip;
open(INFILE,$inputfile);
	push @ip, readline INFILE;
close(INFILE);
my $word;
my @octet;
my $i;
my $j;

for($j = 0; $j < scalar @ip; $j++)
{
	my $word = @ip[$j];
	chop $word; #Get rid of trailing \n
	@octet = split(/\./, $word);
	for($i = 0; $i < $display; $i++)
	{
		if($i != 0){print ".";}
		print @octet[$i];
	}
print "\n";
}
exit(0);
sub usage { die "\nUSAGE: $0 <input file> <display n octets>\n\n";}
