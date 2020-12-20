#include <stdio.h>

int main(void) {
    printf("\e[1m# MyShell i17027\e[0m\n\n");
    printf("\e[1m## Prompt\e[0m\n\n");
    printf("\e[4m(0)[aaaaaaa@localhost /path/to/file] $ help\e[0m\n");
    printf(" |     |                    |           |\n");
    printf(" |     |                    |           --- command input space\n");
    printf(" |     |                    |\n");
    printf(" |     |                    --- current path\n");
    printf(" |     |\n");
    printf(" |     --- username\n");
    printf(" |\n");
    printf(" --- exit status\n\n");
    printf("\e[1m## Available features\e[0m\n\n");
    printf("\e[1m### Default commands\e[0m\n\n");
    printf("- \e[3mcd\e[0m\n");
    printf("- \e[3mexit\e[0m\n");
    printf("- \e[3m./bin/help\e[0m\n");
    printf("- \e[3m./bin/rabbit\e[0m\n\n");
    printf("\e[1m### Operators\e[0m\n\n");
    printf("- \e[3m|\e[0m\n");
    printf("- \e[3m;\e[0m\n");
    printf("- \e[3m||\e[0m\n");
    printf("- \e[3m&&\e[0m\n");
    return 0;
}
