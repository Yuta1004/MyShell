#include <stdio.h>
#include <stdlib.h>

#include "command.h"
#include "../vector/vector.h"

int exit_shell(Vector *argv) {
    printf("Bye...\n");
    exit(0);
}

int not_default_command(Vector *argv) {
    printf("TODO: Impl \"not_default_command\"\n");
    return 0;
}
