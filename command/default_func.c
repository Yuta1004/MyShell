#include <stdio.h>
#include <stdlib.h>

#include <pwd.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>

#include "command.h"
#include "../str/str.h"
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
    uid_t uid = getuid();
    struct passwd *pw = getpwuid(uid);

    int len = command->argv->len;
    if(len == 1) {
        vec_push(command->argv, pw->pw_dir);
    } else if (len == 2) {
        vec_push(command->argv, replace(vec_pop(command->argv), "~", pw->pw_dir, 1));
    } else {
        return 7;   // Argument list too long
    }

    if(chdir(vec_get(command->argv, 1)) < 0) {
        return errno;
    }
    return 0;
}
