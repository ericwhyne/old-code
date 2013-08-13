#!/usr/bin/perl
# Eric Whyne Feb 2004
# License: GPL
# Description: Affine Cipher
my $inputfile, $k;
if(scalar @ARGV != 3){ die "\n\tUSAGE: $0 <input file> <a> <b>\n\n";}
else{ $inputfile = @ARGV[0]; $a = @ARGV[1]; $b = @ARGV[2];}
my (@plaintext, $i);
open(PLAINTEXT,$inputfile);
while(!eof PLAINTEXT){push @plaintext, getc PLAINTEXT}
close(PLAINTEXT);
@plaintext = reverse grep(/[A-Za-z]/, @plaintext);
my $plength = scalar @plaintext;
my $ptnum, $y;
print "A: $a B: $b\t";
for($i=0;$i< $plength; $i++)
{	
	$ptnum = ord(pop @plaintext);
	if($ptnum >= 65 && $ptnum <= 90){ $ptnum = $ptnum - 65;}
	if($ptnum >= 97 && $ptnum <= 122){ $ptnum = $ptnum - 97;}
	# $y = ($k * $ptnum) % 26;
	$y = (($a * $ptnum)+ $b) % 26;
	print chr($y + 65); 
}
print "\n";
