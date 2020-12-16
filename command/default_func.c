#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/types.h>

#include "command.h"
#include "../vector/vector.h"

/* ------------- FOR DEBUG  -------------*/
int cause_error(Vector *argv) {
    if(argv->len != 1) {
        return 0;
    }
    return ((char*)vec_get(argv, 0))[0] - '0';
}

int check_argv(Vector *argv) {
    for(int idx = 0; idx < argv->len; ++ idx) {
        printf("%d: %s\n", idx, vec_get(argv, idx));
    }
    return 0;
}
/* ------------- FOR DEBUG  -------------*/

int exit_shell(Vector *argv) {
    printf("Bye...\n");
    exit(0);
}

int fork_process(Vector *argv) {
    pid_t pid = fork();
    if(pid == 0) {
        execvp(vec_get(argv, 0), (char**)(argv->data));
    }
    int result = -1;
    wait(&result);
    return result;
}