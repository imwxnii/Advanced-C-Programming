// practice2.c 헤더파일

#ifndef _CALCULATOR_H
#define _CALCULATOR_H

int add(int a, int b){
    return a + b;
}

int sub(int a, int b){
    return a - b;
}

int multi(int a, int b){
    return a * b;
}

int printAdd(int a, int b){
    int sum;
    sum = 0;
    for(int i = a; i < b; i++) sum += i;
    return sum;
}

#endif