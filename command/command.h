#ifndef MY_COMMAND_H
#define MY_COMMAND_H

#include <stdio.h>

#include "../vector/vector.h"

typedef struct Command Command;
struct Command {
    int (*func)(void);
    Vector *argv;
    FILE *stdin;
    FILE *stdout;
    FILE *stderr;
    int result;
};

/* convert.c */
Vector* convert_2_command_vec(Vector *inp);

/* exec.c */
int exec_command(Vector *command_vec);

/* default_func.c */
int hello();
int not_default_command();

#endif  // !MY_COMMAND_H