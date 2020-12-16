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
    int (*func)(void);
    Vector *argv;
    FILE *stdin;
    FILE *stdout;
    FILE *stderr;
    int result;
    ExecType exec_type;
};

/* command.c */
Command *__gen_command(int(*func)(void), FILE *set_stdin, FILE *set_stdout, FILE *set_stderr, Vector *argv);

/* convert.c */
Vector* convert_2_command_vec(Vector *inp);

/* exec.c */
int exec_command(Vector *command_vec);

/* default_func.c */
int exit_shell();
int not_default_command();

#endif  // !MY_COMMAND_H