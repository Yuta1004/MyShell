#include <stdio.h>

#include "command.h"

int exit_shell() {
    printf("Bye...\n");
    exit(0);
}

int not_default_command() {
    printf("TODO: Impl \"not_default_command\"\n");
    return 0;
}
