#include <stdio.h>

#include <pwd.h>
#include <unistd.h>
#include <sys/types.h>

#include "str/str.h"
#include "vector/vector.h"

int main(void) {
    // ユーザ情報取得
    uid_t uid = getuid();
    struct passwd *pw = getpwuid(uid);
    printf("Uid: %d\n", uid);
    printf("Name: %s\n", pw->pw_name);
    printf("HomePath: %s\n", pw->pw_dir);

    // ユーザ入力受理
    char inp[256];
    scanf("%256[^\n]", inp);
    Vector *argv = split(inp, ' ');
    for(int idx = 0; idx < argv->len; ++ idx) {
        printf("%d: %s\n", idx, vec_get(argv, idx));
    }

    return 0;
}