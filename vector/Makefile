CC := gcc
GCC := gcc
SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)
CFLAGS := -std=c11 -g -static


build: $(OBJS)
	ld -r $(OBJS) -o libvector.o
