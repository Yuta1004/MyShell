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
        dup2(command->read_p, 0);
        dup2(command->write_p, 1);
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

int display_help(Command *command) {
    printf("\e[1m# MyShell i17027\e[0m\n\n");
    printf("\e[1m## Prompt\e[0m\n\n");
    printf("\e[4m(0)[aaaaaaa@localhost /path/to/file] $ help\e[0m\n");
    printf(" |     |                    |           |\n");
    printf(" |     |                    |           --- command input space\n");
    printf(" |     |                    |\n");
    printf(" |     |                    --- current path\n");
    printf(" |     |\n");
    printf(" |     --- username\n");
    printf(" |\n");
    printf(" --- exit status\n\n");
    printf("\e[1m## Available features\e[0m\n\n");
    printf("\e[1m### Default commands\e[0m\n\n");
    printf("- \e[3mcd\e[0m\n");
    printf("- \e[3mhelp\e[0m\n");
    printf("- \e[3mrabbit\e[0m\n");
    printf("- \e[3mexit\e[0m\n\n");
    printf("\e[1m### Operators\e[0m\n\n");
    printf("- \e[3m;\e[0m\n");
    printf("- \e[3m||\e[0m\n");
    printf("- \e[3m&&\e[0m\n");
    return 0;
}

int display_rabbit_msg(Command *command) {
    printf("-----------------------------------\n");
    printf("|      \e[1mIs the order a rabbit?\e[0m     |\n");
    printf("| Official Web Site: \e[3mgochiusa.com\e[0m |\n");
    printf("------- ---------------------------\n");
    printf("       ⌵ \n");
    printf("      ∩ ∩\n");
    printf("      ||凸|\n");
    printf("     (=･仝･)=\n");
    printf("     ﾉ /⌒)\n");
    printf("  ○(_つUU\n");
    return 0;
}