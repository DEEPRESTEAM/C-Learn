#include<stdio.h>
#include<string.h>

/**
    函数名：strchr
    函数原型：strchr (const char *__s, int __c) __THROW
    函数参数：const char *__s ，int __c(字符)
    返回值 :如果找到，就返回指向该位置char类型的指针，否则返回NULL
*/

int main(int argc, char const *argv[])
{
    char buf[20] = {"hello , hqyj"}; 
    char ch = 'h'; 
    char * chp = strchr(buf , ch);
    if (chp != NULL)
    {
        printf("找到啦 %p\n" , &chp);
    }
    return 0;
}
