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
    int result = 0;
    for(int idx = 0; idx < command_vec->len; ++ idx) {
        // 実行
        Command *command = vec_get(command_vec, idx);
        result = (command->func)(command);

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
    return result;
}