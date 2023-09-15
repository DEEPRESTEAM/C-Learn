#include<stdio.h>
#include<string.h>

/**
 * 将字符串打印
*/

void manner_1(char str[]){
    printf("*****************************************\n");
    for (int i = 0; i < strlen(str); i++)
    {
        printf("%c" , str[i]);
    }
    printf("\n");
    printf("*****************************************\n");
}

void manner_2(char str[]){
    printf("*****************************************\n");
    while (*str)
    {
        printf("%c" , *str);
        str++;
    }
    printf("\n");
    printf("*****************************************\n");
}

int main(int argc, char const *argv[])
{
    
    char str[300] = {"2022年重大项目是:2022年北京冬季奥运会\n2022年奥运会号是:纯洁的冰雪,激情的约会"};
    
    manner_1(str);
    printf("\n");
    manner_2(str);
    return 0;
}
