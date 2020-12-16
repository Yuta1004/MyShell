#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "command.h"
#include "../vector/vector.h"

int (*__name_2_func(char *name))(Command*);

/**
 * # 文字列郡を実行可能な形態に変換して返す
 * ## Params
 * - Vector<char*> *inp: 文字列郡
 * ## Returns
 * - Vector<Command>: Command構造体のVector
 */
Vector* convert_2_command_vec(Vector *inp) {
    Vector *command_vec = vec_new(1);

    for(int idx = 0; idx <inp->len; ++ idx) {
        // コマンド基本情報設定
        Command *command = __gen_command(NULL, NULL);
        command->func = __name_2_func(vec_get(inp, idx));

        // 引数解析
        int old_idx = idx;
        for(++ idx; idx < inp->len; ++ idx) {
            char *elem = vec_get(inp, idx);
            int elem_len = strlen(elem);
            if(elem_len == 1 && strncmp(elem, "|", 1) == 0) {
                command->exec_type = PIPE;
                goto command_parse_loop_end;
            }
            if(elem_len == 1 && strncmp(elem, ";", 1) == 0) {
                command->exec_type = CONTINUE;
                goto command_parse_loop_end;
            }
            if(elem_len == 2 && strncmp(elem, "&&", 2) == 0) {
                command->exec_type = CONTINUE_WITH_SUCCESS;
                goto command_parse_loop_end;
            }
            if(elem_len == 2 && strncmp(elem, "||", 2) == 0) {
                command->exec_type = CONTINUE_WITH_FAILUE;
                goto command_parse_loop_end;
            }
        }

command_parse_loop_end:
        command->argv = vec_cpy(inp, old_idx, idx);
        vec_push(command_vec, command);
    }

    return command_vec;
}

int (*__name_2_func(char *name))(Command*) {
    int len = strlen(name);
    switch(strlen(name)) {
        case 4:
            if(strncmp(name, "argv", 4) == 0) return check_argv;
            if(strncmp(name, "exit", 4) == 0) return exit_shell;
            break;
        case 5:
            if(strncmp(name, "error", 5) == 0) return cause_error;
    }
    return fork_process;
}