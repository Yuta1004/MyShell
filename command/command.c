#include <stdio.h>
#include <stdlib.h>

#include "command.h"
#include "../vector/vector.h"

Command *command_new(int(*func)(Command*), Vector *argv) {
    Command *command = (Command*)calloc(1, sizeof(Command));
    command->func = func;
    command->argv = argv;
    command->exec_type = NORMAL;
    command->read_p = 0;
    command->write_p = 1;
    return command;
}

void command_free(Command *command){
    vec_free(command->argv);
    free(command);
}
