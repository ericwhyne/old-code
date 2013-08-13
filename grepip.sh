# Eric Whyne 2004
# Sloppy regular expression to extract IP addresses from a file.
# usage: grepip.sh <filename>
# example to get the number of uniq ips in a log file:
# grepip.sh logfile.txt | sort | uniq | wc -l
grep -o -E "[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}" $1
