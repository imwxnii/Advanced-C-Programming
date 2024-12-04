//
// 13-14주차 프로그래밍 프로젝트 설명
// >>>>>> 문자열로 된 2진수 두 개를 입력받아 4칙연산 수행
//

#include <stdio.h>
#include <string.h>
#include <math.h>
#define WORD 16

void getBinary(char bin[], char str[], int n){
    int i, j;
    int len = strlen(str);
    for(i = 0; i < n; i++){
        bin[i] = '0';
    }
    bin[n] = '\0';
    for(i = 0, j = len-1; i < len; i++, j--){
        bin[n-1-i] = str[j];
    }
}

void complement2(char bin[], int n){
    int i;
    for(i = 0; i < n; i++){
        bin[i] = (bin[i] == '0') ? '1' : '0';
    }
    
    for(i = n-1; i >= 0; i--){
        if(bin[i] == '0'){
            bin[i] = '1';
            break;
        } else {
            bin[i] = '0';
        }
    }
}

int bin2dec(char bin[], int n){
    int decimal = 0;
    int sign = 1;
    int i;

    if(bin[0] == '1'){
        sign = -1;
        complement2(bin, n);
    }

    for(i = 0; i < n; i++){
        if(bin[i] == '1'){
            decimal += pow(2, n-1-i);
        }
    }

    return decimal * sign;
}

int main(){
    char input1[100];
    char input2[100];
    char op[10];

    char binary1[WORD+1] = {0};
    char binary2[WORD+1] = {0};

    int result;
    int num1, num2;

    printf("<<<<<<input>>>>>>\n");
    gets(input1);
    gets(op);
    gets(input2);
    getBinary(binary1, input1, WORD);
    getBinary(binary2, input2, WORD);   

    num1 = bin2dec(binary1, WORD);
    num2 = bin2dec(binary2, WORD);

    switch(op[0]){
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        case '%':
            result = num1 % num2;
            break;
        default:
            printf("bad operator...\n");
            break;
    }

    printf("%s(%d) %c %s(%d) = %d\n", binary1, num1, op[0], binary2, num2, result);

    return 0;
}