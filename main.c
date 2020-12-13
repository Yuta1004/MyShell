#include <stdio.h>
#include <stdlib.h>

#include <pwd.h>
#include <unistd.h>
#include <sys/types.h>

#include "str/str.h"
#include "vector/vector.h"

void print_init_msg();
void print_fin_msg();

int main(void) {
    /* 起動処理 */
    uid_t uid = getuid();
    struct passwd *pw = getpwuid(uid);
    print_init_msg(uid, pw->pw_name, pw->pw_dir);

    /* シェル本体処理部 */
    while(1) {
        char inp[256];
        printf(">> ");
        scanf("%256[^\n]", inp);
        Vector *argv = split(inp, ' ');
        vec_free(argv);
        break;
    }

    /* 終了時処理 */
    print_fin_msg();
    return 0;
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

void print_fin_msg() {
    printf("\nBye...\n");
}