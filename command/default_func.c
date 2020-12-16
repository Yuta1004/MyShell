#include <stdio.h>
#include <stdlib.h>

#include <errno.h>
#include <unistd.h>
#include <sys/types.h>

#include "command.h"
#include "../vector/vector.h"

int exit_shell(Command *command) {
    printf("Bye...\n");
    exit(0);
}

int fork_process(Command *command) {
    pid_t pid = fork();
    if(pid == 0) {
        vec_push(command->argv, NULL);
        execvp(vec_get(command->argv, 0), (char**)(command->argv->data));
        exit(errno);
    } else if(pid < 0) {
        return errno;
    }
    int result = -1;
    wait(&result);
    return result/256;
}

int change_directory(Command *command) {
    if(command->argv->len != 2) {
        return 7;
    }
    if(chdir(vec_get(command->argv, 1)) < 0) {
        return errno;
    }
    return 0;
}