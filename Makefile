CC := gcc
GCC := gcc
SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)
CFLAGS := -std=c11 -g -static


build-run:
	make build
	make run

build: $(OBJS)
	$(GCC) -o myshell_i17027 $(OBJS)

run:
	./myshell_i17027

clean:
	rm -rf $(OBJS)

.PHONY: clean