CC := gcc
GCC := gcc
SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)
CFLAGS := -g -static


build: $(OBJS)
	ld -r $(OBJS) -o libvector.o
