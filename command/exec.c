#include "../vector/vector.h"
#include "../command/command.h"

/**
 * # コマンド実行
 * ## Params
 * - Vector<Command*> *command_vec: 実行対象コマンド群
 * ## Returns
 * - int: 実行結果
 */
int exec_command(Vector *command_vec) {
    // TODO: | 対応
    int result = -1;
    for(int idx = 0; idx < command_vec->len; ++ idx) {
        // 実行
        Command *command = vec_get(command_vec, idx);
        result = (command->func)(command->argv);

        // 実行継続確認
        if(command->exec_type == CONTINUE_WITH_SUCCESS && result != 0){
            break;
        }
        if(command->exec_type == CONTINUE_WITH_FAILUE && result == 0){
            break;
        }
    }
    return result;
}