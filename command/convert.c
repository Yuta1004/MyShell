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

    for(int idx = 0; idx <inp->len; ++ idx) {
        // コマンド基本情報設定
        Command *command = __gen_command(NULL, stdin, stdout, stderr, NULL);
        command->func = __name_2_func(vec_get(inp, idx));

        // 引数解析
        int old_idx = idx;
        for(++ idx; idx < inp->len; ++ idx) {
            char *elem = vec_get(inp, idx);
            int elem_len = strlen(elem);
            if(elem_len == 1 && strncmp(elem, ";", 1) == 0) {
                command->exec_type = CONTINUE;
                goto command_parse_loop_end;
            }
        }

command_parse_loop_end:
        command->argv = vec_cpy(inp, old_idx+1, idx+1);
        vec_push(command_vec, command);
    }

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