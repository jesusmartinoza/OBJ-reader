# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=g++
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
CFLAGS=-c -Wall

all: hello

hello: main.o ObjModel.o ObjObject.o ObjVertex.o
	$(CC) main.o ObjModel.o ObjObject.o ObjVertex.o -o main

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

ObjModel.o: ObjModel.cpp
	$(CC) $(CFLAGS) ObjModel.cpp

ObjObject.o: ObjObject.cpp
	$(CC) $(CFLAGS) ObjObject.cpp

ObjVertex.o: ObjVertex.cpp
	$(CC) $(CFLAGS) ObjVertex.cpp

clean:
	rm -rf *.o hello
