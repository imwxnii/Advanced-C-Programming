#include <stdio.h>
#include <string.h> // strlen() 이용
#define SIZE 100

int main(){
    char input[SIZE];
    FILE* fp = NULL;

    if((fp=fopen("output.bin", "wb")) == NULL){
        printf("error...");
        return 0;
    }

    gets(input);
    //fputs(input, fp);
    fwrite(input, strlen(input), 1, fp);

    fclose(fp);

    return 0;
}