#include <stdio.h>

#include <pwd.h>
#include <unistd.h>
#include <sys/types.h>

#include "str/str.h"
#include "vector/vector.h"

void print_init_msg();
void print_fin_msg();

int main(void) {
    print_init_msg();

    // ユーザ入力受理
    char inp[256];
    scanf("%256[^\n]", inp);
    Vector *argv = split(inp, ' ');
    for(int idx = 0; idx < argv->len; ++ idx) {
        printf("%d: %s\n", idx, vec_get(argv, idx));
    }

    print_fin_msg();
    return 0;
}

void print_init_msg() {
    uid_t uid = getuid();
    struct passwd *pw = getpwuid(uid);
    printf("------------------------------------------------------------------------------------------------------------\n");
    printf("|  ####      ##     ######    ####     ####    ######                     ###                ###      ###  |\n");
    printf("|   ##      ###     ##  ##   ##  ##   ##  ##   ##  ##                      ##                 ##       ##  |\n");
    printf("|   ##       ##         ##   ## ###       ##       ##             #####    ##       ####      ##       ##  |\n");
    printf("|   ##       ##        ##    ######     ###       ##             ##        #####   ##  ##     ##       ##  |\n");
    printf("|   ##       ##       ##     ### ##    ##        ##               #####    ##  ##  ######     ##       ##  |\n");
    printf("|   ##       ##       ##     ##  ##   ##  ##     ##                   ##   ##  ##  ##         ##       ##  |\n");
    printf("|  ####    ######     ##      ####    ######     ##              ######   ###  ##   #####    ####     #### |\n");
    printf("------------------------------------------------------------------------------------------------------------\n");
    printf("Hello %s(%d)! (HomeDir => %s)\n\n", pw->pw_name, uid, pw->pw_dir);
}

void print_fin_msg() {
    printf("\nBye...\n");
}