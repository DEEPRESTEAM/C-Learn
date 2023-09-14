#include<stdio.h>
#include<string.h>


//复制和链接函数

/**
    函数名：strcpy
    函数声明：extern char *strcpy (char *__restrict __dest, const char *__restrict __src)
    函数参数：char *__restrict __dest ，const char *__restrict __src
    函数返回值：char *strcpy
    函数作用：将后面参数的值复制给第一个参数，值会被覆盖掉
*/

/**
    函数名：strcat
*/



int main(int argc, char const *argv[])
{
    char ch1[20] = {"hello"};
    char ch2[20] = {"dsdsdsdssdsds"};

    printf("ch1 = %s\n" , ch1);
    printf("ch2 = %s\n" , ch2);

    //strcpy(ch2 , ch1);
    strcat(ch2 , ch1);

    printf("ch1 = %s\n" , ch1);
    printf("ch2 = %s\n" , ch2);


    return 0;
}
