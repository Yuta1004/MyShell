#include <stdio.h>
#include <stdlib.h>

#include "command.h"

Command *command_new(int(*func)(Command*), Vector *argv) {
    Command *command = (Command*)calloc(1, sizeof(Command));
    command->func = func;
    command->argv = argv;
    command->exec_type = NORMAL;
    return command;
}
