#include <stdio.h>
#include <stdlib.h>

#include "command.h"
#include "../vector/vector.h"

void (*__name_2_func(char *name))(void);

/**
 * # 文字列郡を実行可能な形態に変換して返す
 * ## Params
 * - Vector<char*> *inp: 文字列郡
 * ## Returns
 * - Vector<Command>: Command構造体のVector
 */
Vector* convert_2_command_vec(Vector *inp) {
    // コマンド構造体準備
    Command *command = (Command*)calloc(1, sizeof(Command));
    command->func = __name_2_func(vec_get(inp, 0));
    command->result = -1;
    command->stdin = stdin;
    command->stdout = stdout;
    command->stderr = stderr;
    command->argv = vec_cpy(inp);
    vec_remove(command->argv, 0);

    Vector *command_vec = vec_new(1);
    vec_push(command_vec, command);
    return command_vec;
}

void (*__name_2_func(char *name))(void) {
    if(strncmp(name, "hello", 5) == 0) return hello;
    return not_default_command;
}