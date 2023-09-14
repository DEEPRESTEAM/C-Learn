#include<stdio.h>
#include<string.h>
//  学习C语言的函数
//  学习方式
/*
    函数原型
    参数
    返回值
    功能
*/



/**
    strlen
    函数原型：extern size_t strlen (const char *__s)
    参数：   const char *__s        要检测的字符串
    返回值： size_t              返回字符串中的个数
    功能：  检测_s  字符串的长度
*/

/*
    strcmp
    函数原型：extern int strcmp (const char *__s1, const char *__s2)
    参数：  const char *__s1 ， const char *__s2    要比较的字符串
    返回值  int     返回一个整形数字
    功能：  比较两个字符串是否相同  相同返回 0 不同返回 1
*/
int main(int argc, char const *argv[])
{
    char buf[255] = {0};
    char buf_1[255]= {0};
    printf("请输入账户一：");
    scanf("%s" , buf);
    getchar();
    printf("请输入账户二：");
    scanf("%s" , buf_1);
    getchar();
    int buf_siz = strlen(buf);
    if (buf_siz > 5)
    {
        printf("你的账号长度太长，请重新输入");
    }
    if (!strcmp(buf_1 , buf))
    {
        printf("账户名相同");
    }
    
    
    
    return 0;
}
