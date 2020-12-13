#include <stdio.h>
#include <stdlib.h>

#include <pwd.h>
#include <unistd.h>
#include <sys/types.h>

#include "str/str.h"
#include "vector/vector.h"
#include "command/command.h"

void print_init_msg();
void exit_shell();

int main(void) {
    /* 起動処理 */
    uid_t uid = getuid();
    struct passwd *pw = getpwuid(uid);
    print_init_msg(uid, pw->pw_name, pw->pw_dir);

    /* シェル本体処理部 */
    int result = 0;
    while(1) {
        // コマンド入力
        char inp[256];
        printf("(%d)[%s@localhost %s] $ ", result, pw->pw_name, "/path/to/current");
        fgets(inp, 256, stdin);
        Vector *inp_vec = split(inp, ' ');

        // コマンド実行
        Vector *command_vec = convert_2_command_vec(inp_vec);
        result = exec_command(command_vec);

        // 後片付け
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

/**
 *  # シェルを終了する
 */
void exit_shell() {
    printf("\nBye...\n");
    exit(0);
}