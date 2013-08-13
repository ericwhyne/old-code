#!/bin/bash
# Eric Whyne 2004
# command to organize a stream of mp3 files by their modification times
ls *.mp3 | perl -MFile::Copy -ne 'chomp;$mt=(stat($_))[9];print "Moving: $_ to ".$mt." - ".$_."\n";move($_,$mt." - ".$_);'
