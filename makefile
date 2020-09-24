CC=g++
CFLAGS=-c -Wall
NAME=queue
RUN_ARGS=

all: main
	./$(NAME) $(RUN_ARGS)

main: main.o
	@$(CC) main.o -o $(NAME)

main.o: main.cpp
	@$(CC) $(CFLAGS) main.cpp 

clean:
	rm -rf *.o queue