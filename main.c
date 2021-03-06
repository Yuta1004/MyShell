#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pwd.h>
#include <unistd.h>
#include <sys/types.h>

#include "str/str.h"
#include "vector/vector.h"
#include "command/command.h"

int main(void) {
    /* 起動処理 */
    uid_t uid = getuid();
    struct passwd *pw = getpwuid(uid);
    printf("Hello %s(%d)! (HomeDir: %s)\n", pw->pw_name, uid, pw->pw_dir);
    printf("\e[1mFirst, type './bin/help' to show some useful messages!\e[0m\n\n");

    /* シェル本体処理部 */
    int result = 0;
    while(1) {
        // プロンプト出力
        char cpath[128];
        getcwd(cpath, 128);
        printf("(%d)[%s@localhost %s] $ ", result, pw->pw_name, cpath);

        // コマンド入力
        char inp[256] = {0};
        fflush(stdin);
        scanf("%256[^\n]", inp);
        Vector *inp_vec = split(inp, ' ');

        // コマンド実行
        Vector *command_vec = convert_2_command_vec(inp_vec);
        result = exec_command(command_vec);
        if(result > 0) {
            fprintf(stderr, "%s\n", strerror(result));      // 必要であればエラーメッセージ表示
        }
        printf("\n");

        // 後片付け
        for(int idx = 0; idx < command_vec->len; ++ idx) {
            command_free(vec_get(command_vec, idx));
        }
        vec_free(command_vec);
        vec_free(inp_vec);
    }
}
