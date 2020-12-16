#include <stdio.h>
#include <stdlib.h>

#include "command.h"

Command *__gen_command(int(*func)(void), FILE *set_stdin, FILE *set_stdout, FILE *set_stderr, Vector *argv) {
    Command *command = (Command*)calloc(1, sizeof(Command));
    command->func = func;
    command->result = -1;
    command->stdin = set_stdin;
    command->stdout = set_stdout;
    command->stderr = set_stderr;
    command->argv = argv;
    return command;
}
