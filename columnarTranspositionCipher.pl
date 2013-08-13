#!/usr/bin/perl
# Eric Whyne Feb 2004
# License: GPL
# Description: Columnar encryption/decryption.
use strict;
my $inputfile;
my @plaintext;
my ($plaintext_value, $letter_chosen, $c, $i, $r, $method);

if(scalar @ARGV != 3){ usage();} 
else{ 
	$inputfile = @ARGV[0]; 
	$method = @ARGV[1]; 
	$c = @ARGV[2];	
}

open(PLAINTEXT,$inputfile);
	while(!eof PLAINTEXT){ push @plaintext, getc PLAINTEXT; }
close(PLAINTEXT);

@plaintext = grep(/[A-Za-z0-9]/, @plaintext); # Filter the file
my $plaintext_length = scalar @plaintext;
$r = ($plaintext_length / $c);  # Column Length
unshift(@plaintext, 0); # This is done so the formula given with the LAB works.

if($method eq '-e') #encrypt
{
 for($i=1; $i<($plaintext_length+1); $i++)
 {
  $letter_chosen = ((($i-1) % $r) * $c) + (($i-1)/$r)+1;
  print @plaintext[$letter_chosen];
 }
}
elsif($method eq '-d')   #decrypt
{
 for($i = 1; $i < ($plaintext_length+1); $i++)
 {
  $letter_chosen = ((($i-1) % $c) * $r) + (($i-1)/$c)+1; 
  print @plaintext[$letter_chosen];
 }
}
else
{
	usage();
}

print "\n";
exit(0);
sub usage { die "USAGE: $0 <input file> <-e or -d> <columns>\n";}	

