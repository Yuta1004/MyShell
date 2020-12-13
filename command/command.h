#ifndef MY_COMMAND_H
#define MY_COMMAND_H

#include "../vector/vector.h"

typedef struct Command Command;
struct Command {
    void *func;
    Vector *argv;
    int stdin;
    int stdout;
    int stderr;
    int result;
};

#endif  // !MY_COMMAND_H