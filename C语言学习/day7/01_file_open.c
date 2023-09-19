#include<stdio.h>   //标准输入输出
// extern FILE *fopen (const char *__restrict __filename,  const char *__restrict __modes) __wur;
//FILE * 文件结构体指针

// extern FILE *fopen (const char *__restrict __filename,  const char *__restrict __modes) __wur;
/**
 * 函数原型
 * extern FILE *fopen (const char *__restrict __filename,  const char *__restrict __modes) __wur;
 * 参数名：
 *      __filename：文件名称
 *      __modes：文件打开的模式
 * 返回值：FILE * 文件打开成功，返回该文件的文件指针    失败返回NULL
 * 功能：打开文件
*/

//extern int fclose (FILE *__stream);
/**
 * 函数原型：extern int fclose (FILE *__stream);
 * 函数参数：
 *      __stream：文件指针
 * 返回值：
 * 功能：关闭文件
*/


int main(int argc, char const *argv[])
{
    FILE * fp = fopen("hello.txt" , "a+");//打开文件
    if (fp == NULL)
    {
        printf("打开文件失败\n");
        return -1;
    }
    fclose(fp);//关闭文件
    fp = NULL;
    remove("hello.txt");
    return 0;
}
