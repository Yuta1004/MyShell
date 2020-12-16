#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "command.h"
#include "../vector/vector.h"

int (*__name_2_func(char *name))(void);

/**
 * # 文字列郡を実行可能な形態に変換して返す
 * ## Params
 * - Vector<char*> *inp: 文字列郡
 * ## Returns
 * - Vector<Command>: Command構造体のVector
 */
Vector* convert_2_command_vec(Vector *inp) {
    // TODO: |, ||, &&
    Vector *command_vec = vec_new(1);
    int(*func)(void) = __name_2_func(vec_get(inp, 0));
    Command *command = __gen_command(func, stdin, stdout, stderr, vec_cpy(inp, 1, inp->len));
    vec_push(command_vec, command);
    return command_vec;
}

int (*__name_2_func(char *name))(void) {
    int len = strlen(name);
    switch(strlen(name)) {
        case 4+1:
            if(strncmp(name, "exit", 4) == 0) return exit_shell;
            break;
    }
    return not_default_command;
}