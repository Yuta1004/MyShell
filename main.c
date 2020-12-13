#include <stdio.h>
#include <stdlib.h>

#include <pwd.h>
#include <unistd.h>
#include <sys/types.h>

#include "str/str.h"
#include "vector/vector.h"

void print_init_msg();
void exit_shell();

int main(void) {
    /* 起動処理 */
    uid_t uid = getuid();
    struct passwd *pw = getpwuid(uid);
    print_init_msg(uid, pw->pw_name, pw->pw_dir);

    /* シェル本体処理部 */
    while(1) {
        // コマンド入力
        char inp[256];
        printf(">> ");
        fgets(inp, 256, stdin);
        Vector *argv = split(inp, ' ');

        // TODO: コマンド実行

        // 後片付け
        vec_free(argv);
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