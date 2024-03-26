CC = g++
CFLAGS = -Wall -g


build: main

main: obj
	$(CC) $(CFLAGS) -o main main.o tokenizer.o highlighter.o

obj:
	$(CC) $(CFLAGS) -c main.cpp tokenizer.cpp highlighter.cpp

clean:
	rm -rf *.o main
