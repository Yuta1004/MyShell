#ifndef MY_COMMAND_H
#define MY_COMMAND_H

#include <stdio.h>

#include "../vector/vector.h"

typedef enum ExecType ExecType;
enum ExecType {
    NORMAL,
    CONTINUE,   // &&
    CONTINUE_WITH_SUCCESS,  // ;
    CONTINUE_WITH_FAILUE,   // ||
    PIPE    // |
};

typedef struct Command Command;
struct Command {
    int (*func)(Vector*);
    Vector *argv;
    ExecType exec_type;
};

/* command.c */
Command *__gen_command(int(*func)(Vector*), Vector *argv);

/* convert.c */
Vector* convert_2_command_vec(Vector *inp);

/* exec.c */
int exec_command(Vector *command_vec);

/* default_func.c */
int cause_error(Vector *argv);
int check_argv(Vector *argv);
int exit_shell(Vector *argv);
int fork_process(Vector *argv);

#endif  // !MY_COMMAND_H