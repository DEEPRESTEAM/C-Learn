#include<stdio.h>
#include<string.h>
/**文件定位：定位光标
 * 函数原型：extern int fseek (FILE *__stream, long int __off, int __whence);
 * 函数参数：FILE *__stream：需要操作的文件指针
 * 返回值：读取成功返回一个字符
 * 功能：读取的字符的ASCII值，读到文件结束或发生错误返回EOF
*/
FILE * file_open(char * file_name , char * modes){
    FILE * fp = fopen(file_name , modes);
    if (fp == NULL)
    {
        printf("打开文件失败\n");
        return NULL;
    }
    return fp;
}


int main(int argc, char const *argv[])
{
    FILE * fp = file_open("hello.txt" , "a+");//打开文件
    if (fp == NULL)
    {
        return 0;
    }
    char ch[255] = "hello       hello";
    //写入 hello hello  
    fputs(ch , fp);
    //文件定位
    fseek(fp , 6 , SEEK_SET);
    strcpy(ch , "徐智伟");
    //再次写入 徐智伟
    fputs(ch , fp);

    //重新文件定位
    fseek(fp , 0 , SEEK_SET);
    //读取 重头开始读
    fgets(ch , 255 , fp);

    printf("%s\n" , ch);
    fclose(fp);//关闭文件
    fp = NULL;
    //remove("hello.txt");
    return 0;
}