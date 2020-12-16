#include <stdio.h>
#include <stdlib.h>

#include "command.h"
#include "../vector/vector.h"

int check_argv(Vector *argv) {
    for(int idx = 0; idx < argv->len; ++ idx) {
        printf("%d: %s\n", idx, vec_get(argv, idx));
    }
    return 0;
}

int exit_shell(Vector *argv) {
    printf("Bye...\n");
    exit(0);
}

int not_default_command(Vector *argv) {
    printf("TODO: Impl \"not_default_command\"\n");
    return 0;
}
