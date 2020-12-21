#include <stdio.h>
#include <string.h>

#include <unistd.h>

#include "../vector/vector.h"
#include "../command/command.h"

#define READ    0
#define WRITE   1
#define OLD     0
#define NEW     1

void __update_pipe(int pipe_v[][2]);
void __close_pipe_all(int pipe_v[][2]);

/**
 * # コマンド実行
 * ## Params
 * - Vector<Command*> *command_vec: 実行対象コマンド群
 * ## Returns
 * - int: 実行結果
 */
int exec_command(Vector *command_vec) {
    int result = 0, old_exec_type = NORMAL;
    int pipe_v[2][2];
    memset(pipe_v, 0, sizeof(int)*4);

    for(int idx = 0; idx < command_vec->len; ++ idx) {
        Command *command = vec_get(command_vec, idx);

        // 標準入出力付け替え
        if(old_exec_type != PIPE) {
            __close_pipe_all(pipe_v);
        }
        if(command->exec_type == PIPE || old_exec_type == PIPE) {
            __update_pipe(pipe_v);
            if(pipe_v[OLD][READ] != 0)
                command->read_p = pipe_v[OLD][READ];
            if(command->exec_type == PIPE)
                command->write_p = pipe_v[NEW][WRITE];
        }

        // コマンド実行
        result = (command->func)(command);
        old_exec_type = command->exec_type;

        // 実行継続確認
        switch(command->exec_type) {
            case CONTINUE_WITH_FAILUE:
                if(result == 0) return 0;
                break;
            case CONTINUE_WITH_SUCCESS:
                if(result != 0) return result;
                break;
            default:;
        }
    }

    __close_pipe_all(pipe_v);
    return result;
}

void __update_pipe(int pipe_v[][2]) {
    // パイプ処理の始点
    if(pipe_v[NEW][READ] == 0) {
        pipe(pipe_v[NEW]);
        return;
    }

    // パイプ処理の中継
    if(pipe_v[OLD][READ] != 0) {
        close(pipe_v[OLD][READ]);
        close(pipe_v[OLD][WRITE]);
    }
    pipe_v[OLD][READ] = pipe_v[NEW][READ];
    pipe_v[OLD][WRITE] = pipe_v[NEW][WRITE];
    pipe(pipe_v[NEW]);
    close(pipe_v[OLD][WRITE]);
}

void __close_pipe_all(int pipe_v[][2]) {
    if(pipe_v[OLD][READ] != 0) close(pipe_v[OLD][READ]);
    if(pipe_v[OLD][WRITE] != 0) close(pipe_v[OLD][WRITE]);
    if(pipe_v[NEW][READ] != 0) close(pipe_v[NEW][READ]);
    if(pipe_v[NEW][WRITE] != 0) close(pipe_v[NEW][WRITE]);
    memset(pipe_v, 0, sizeof(int)*4);
}
