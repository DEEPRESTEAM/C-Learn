#include<stdio.h>
#define FILEMAX 255
/**
 * 函数原型：fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
 * 函数参数：char *__restrict __s：接收用的字符串数组       FILE *__restrict __stream：文件指针     int __n：读取范围   
 * 返回值：
 * 功能：读取文件中字符串
*/


/**
 * 函数原型：extern int fputs (const char *__restrict __s, FILE *__restrict __stream);
 * 函数参数：char *__restrict __s：写入字符串       FILE *__restrict __stream：文件指针
 * 返回值：写入成功返回 1，失败返回 EOF
 * 功能：写入字符串到文件中
*/

int main(int argc, char const *argv[])
{
    FILE * fp = fopen("hello.txt" , "a+");//打开文件
    if (fp == NULL)
    {
        printf("打开文件失败\n");
        return -1;
    }
    //读取
    // char buf[255] = "0";
    // fgets(buf , FILEMAX , fp);  
    // printf("%s\n" , buf);

    //写入
    char buf[FILEMAX] = {"徐智伟,陈宝龙"};
    int temp = fputs(buf , fp);
    printf("%d\n" , temp);
    fclose(fp);//关闭文件
    fp = NULL;
    //remove("hello.txt");
    return 0;
}
