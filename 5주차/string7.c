// 기존 소문자 counting 에 대문자와 숫자도 추가

#include <stdio.h>

int main() {
    char input[200] = "";
    int count[36] = {0};
    int ch;
    int i = 0;

    while((ch = getchar()) != EOF) {
        input[i++] = ch;
    }

    i = 0;
    while(input[i] != '\0') {
        if(input[i] >= 'a' && input[i] <= 'z') {
            count[input[i] - 'a']++;
        } else if(input[i] >= 'A' && input[i] <= 'Z') {
            count[input[i] - 'A']++;
        } else if(input[i] >= '0' && input[i] <= '9') {
            count[26 + (input[i] - '0')]++;
        }
        i++;
    }

    printf("입력문자열 : %s\n", input);
    for(int i = 0; i < 26; i++) printf("%c 출현횟수 : %d\n", 'a'+i, count[i]);
    for(int i = 0; i < 26; i++) printf("%c 출현횟수 : %d\n", 'A'+i, count[i]);
    for(int i = 0; i < 10; i++) printf("%c 출현횟수 : %d\n", '0'+i, count[26 + i]);

    return 0;
}
