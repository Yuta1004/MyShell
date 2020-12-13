#include <stdio.h>

#include <pwd.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    // ユーザ情報取得
    uid_t uid = getuid();
    struct passwd *pw = getpwuid(uid);
    printf("Uid: %d\n", uid);
    printf("Name: %s\n", pw->pw_name);
    printf("HomePath: %s\n", pw->pw_dir);

    return 0;
}