#include <stdio.h>

int main(void) {
    char line[128];
    while (fgets(line, sizeof(line), stdin) != NULL) {
        printf("%s\n", line);
    }
    printf("EOF\n");
}