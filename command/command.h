#ifndef MY_COMMAND_H
#define MY_COMMAND_H

#include "../vector/vector.h"

typedef struct Command Command;
struct Command {
    void (*func)(void);
    Vector *argv;
    FILE *stdin;
    FILE *stdout;
    FILE *stderr;
    int result;
};

#endif  // !MY_COMMAND_H