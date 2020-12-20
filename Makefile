CC := gcc
GCC := gcc
SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)
LIBRARIES := $(wildcard **/lib*.o)
CFLAGS := -std=c11 -g -static


build-run:
	make build-lib
	make build
	make run

build: $(OBJS)
	make -C bin
	$(GCC) -o myshell_i17027 $(OBJS) $(LIBRARIES)

build-lib:
	make -C vector
	make -C str
	make -C command

run:
	./myshell_i17027

clean:
	rm -rf **/*.o

.PHONY: clean