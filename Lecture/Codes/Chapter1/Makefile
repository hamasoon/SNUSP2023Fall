CC = gcc
CFLAGS = -Wall

virtual_memory: virtual_memory.o
	$(CC) $(CFLAGS) -o virtual_memory virtual_memory.o

memory: virtual_memory
	./virtual_memory

process_object: process.o
	$(CC) $(CFLAGS) -o process process.o

process: process_object
	./process

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -rf *.o