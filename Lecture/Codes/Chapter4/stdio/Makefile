#---------------------------------------------------------------------------------------------------
# M1522.000800 System Programming                                         Seoul National University
#
# Author: Bernhard Egger <bernhard@csap.snu.ac.kr>
# (C) Computer Systems and Platforms Laboratory, Seoul National University
#

CC=gcc
CFLAGS=-Wall

.PHONY: data clean

data:
	dd if=/dev/random of=data.dat bs=1024 count=10240

%: %.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(patsubst %.c,%,$(wildcard *.c)) *.dat test

mrproper: clean
