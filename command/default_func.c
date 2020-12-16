#include <stdio.h>
#include <stdlib.h>

#include <errno.h>
#include <unistd.h>
#include <sys/types.h>

#include "command.h"
#include "../vector/vector.h"

/* ------------- FOR DEBUG  -------------*/
int cause_error(Command *command) {
    if(command->argv->len != 1) {
        return 0;
    }
    return ((char*)vec_get(command->argv, 0))[0] - '0';
}

int check_argv(Command *command) {
    for(int idx = 0; idx < command->argv->len; ++ idx) {
        printf("%d: %s\n", idx, vec_get(command->argv, idx));
    }
    return 0;
}
/* ------------- FOR DEBUG  -------------*/

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
        return -124;
    }
    int result = -112;
    wait(&result);
    return result/256;
}