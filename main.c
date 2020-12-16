#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pwd.h>
#include <unistd.h>
#include <sys/types.h>

#include "str/str.h"
#include "vector/vector.h"
#include "command/command.h"

void print_init_msg();

int main(void) {
    /* 起動処理 */
    uid_t uid = getuid();
    struct passwd *pw = getpwuid(uid);
    print_init_msg(uid, pw->pw_name, pw->pw_dir);

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

void print_init_msg(int uid, char *username, char* homedir) {
    printf("------------------------------------------------------------------------------------------------------------\n");
    printf("|  ####      ##     ######    ####     ####    ######                     ###                ###      ###  |\n");
    printf("|   ##      ###     ##  ##   ##  ##   ##  ##   ##  ##                      ##                 ##       ##  |\n");
    printf("|   ##       ##         ##   ## ###       ##       ##             #####    ##       ####      ##       ##  |\n");
    printf("|   ##       ##        ##    ######     ###       ##             ##        #####   ##  ##     ##       ##  |\n");
    printf("|   ##       ##       ##     ### ##    ##        ##               #####    ##  ##  ######     ##       ##  |\n");
    printf("|   ##       ##       ##     ##  ##   ##  ##     ##                   ##   ##  ##  ##         ##       ##  |\n");
    printf("|  ####    ######     ##      ####    ######     ##              ######   ###  ##   #####    ####     #### |\n");
    printf("------------------------------------------------------------------------------------------------------------\n");
    printf("Hello %s(%d)! (HomeDir => %s)\n\n", username, uid, homedir);
}
