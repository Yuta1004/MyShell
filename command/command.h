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
    int (*func)(Command*);
    Vector *argv;
    ExecType exec_type;
};

/* command.c */
Command *command_new(int(*func)(Command*), Vector *argv);
void command_free(Command *command);

/* convert.c */
Vector* convert_2_command_vec(Vector *inp);

/* exec.c */
int exec_command(Vector *command_vec);

/* default_func.c */
int exit_shell(Command *argv);
int fork_process(Command *argv);
int change_directory(Command *argv);
int display_help(Command *command);

#endif  // !MY_COMMAND_H