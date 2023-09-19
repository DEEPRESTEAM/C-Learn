#include<stdio.h>
/**
 * 函数原型：extern int fgetc (FILE *__stream);
 * 函数参数：FILE *__stream：需要操作的文件指针
 * 返回值：读取成功返回一个字符
 * 功能：读取的字符的ASCII值，读到文件结束或发生错误返回EOF
*/


/**
 * 函数原型：extern int fputc (int __c, FILE *__stream);
 * 函数参数：int __c：要输出的字符  FILE *__stream：需要操作的文件指针
 * 返回值：写入成功返回写入的字符，失败返回EOF
 * 功能：写入一个字符到文件中
*/

int main(int argc, char const *argv[])
{
    FILE * fp = fopen("hello.txt" , "a+");//打开文件
    if (fp == NULL)
    {
        printf("打开文件失败\n");
        return -1;
    }
    char ch = 'a';
    fputc(ch , fp);
    fclose(fp);//关闭文件
    fp = NULL;
    //remove("hello.txt");
    return 0;
}
