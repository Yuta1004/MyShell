CC := gcc
GCC := gcc

all:
	make help
	make rabbit
	make pipe_test

help: help.c
	$(CC) -o help help.c

rabbit: rabbit.c
	$(CC) -o rabbit rabbit.c

pipe_test: pipe_test.c
	$(CC) -o pipe_test pipe_test.c
