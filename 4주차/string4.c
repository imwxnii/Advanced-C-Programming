#include <stdio.h>

int main() {
    int ch;
    char message[100];
    int i = 0;
    while((ch = getchar()) != '\n') {
        message[i++] = ch;
    }
    message[i] = '\0'; // 실수하지 않게 주의!!!
    printf("%s", message);
    return 0;
}