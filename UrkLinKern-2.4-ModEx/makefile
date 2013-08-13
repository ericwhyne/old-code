# Eric Whyne (c) 2003
# Makefile for the kernel module

# You only have to edit these two lines to change the names of the
# source and object files. Note: The .o extension for the object file is
# automagically appended.
SRC = UrkModule.c
OBJS = TimeExample

RP = ReadProcTimeFile

LINUX_ROOT = /usr/src/linux
CFLAGS	=  -DMODVERSIONS \
 -DMODULE \
 -I$(LINUX_ROOT)/include \
 -c \
 -g \
 -O1 \
 -o $(OBJS).o
CC = gcc

all:
	$(CC) $(CFLAGS) $(SRC)

rp:
	$(CC) $(RP).c -o $(RP)

load: all
	insmod $(OBJS).o

unload:
	rmmod $(OBJS) 

clean:
	rm -f $(OBJS).o
	rm -f $(RP)
