CC = gcc
CFLAGS = -Wall -g 

file: file.o
	$(CC) $(CFLAGS) file.o -o file

file_size: file_size.o
	$(CC) $(CFLAGS) file_size.o -o file_size

run:
	./file_size

file_size_unix:
	sh file_size.sh

word_sort:
	sh word_sort.sh