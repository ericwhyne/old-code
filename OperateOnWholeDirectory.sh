#!/bin/bash
# What: Perform an operation on a whole directory of files.
# Why: Some applications don't support multiple file inputs well.
# When: 2004
for fname in `ls`
do
	echo Operating on $fname
	# Do something here to $fname
	# example: StandardizeFilename.pl $fname
done
echo Done.
