#include <stdio.h>   //  标准输入输出



/*
函数原型：
    fprintf (FILE *__restrict __stream, const char *__restrict __fmt, ...)
函数参数：
    ...         格式 可变参数
    __fmt       格式化字符
    __stream    文件指针
返回值：

功能：
    写入字符串到文件中去
*/

/*
函数原型：
    extern int fscanf (FILE *__restrict __stream,
		   const char *__restrict __format, ...) __wur;
函数参数：
    ...         格式 可变参数
    __fmt       格式化字符
    __stream    文件指针
返回值：

功能：
    格式化读取文件中的字符给到__fmt
    
*/

// 定义结构体
typedef struct student
{
    char name[255];
    int id;
}student;

#define FILE_MAX 255

int main(int argc, char const *argv[])
{
    student stu_name[16] = {
        {"张老师" , 1},{"王老师" , 1},{"罗老师" , 1},{"陈老师" , 1},
        {"徐老师" , 1},{"韩老师" , 1},{"樊老师" , 1},{"左老师" , 1},
        {"李老师" , 1},{"刘老师" , 1},{"黎老师" , 1},{"高老师" , 1},
        {"陈老师" , 1},{"邓老师" , 1},{"胡老师" , 1},{"孟老师" , 1}
    };
    student stu_name1[16];
    // 打开文件
    FILE * fp = fopen("hello.txt" , "a+");
    if (fp == NULL)
    {
        printf("文件打开失败!!!!\n");
        return -1;
    }
    char buf[FILE_MAX] = "张老师";
    
    // for (int i = 0; i < 16; i++)
    // {
    //     fprintf(fp , "姓名 : %s , 人物id : %d\n" , stu_name[i].name , stu_name[i].id += i);
    // }

    for (int i = 0; i < 16; i++)
    {
        fscanf(fp , "姓名 : %s , 人物id : %d\n" , stu_name1[i].name , &stu_name1[i].id);
    }
    for (int i = 0; i < 16; i++)
    {
        printf("姓名 : %s , 人物id : %d\n" , stu_name1[i].name , stu_name1[i].id);
    }
    
    


    // 文件关闭的操作
    fclose(fp);
    fp = NULL;
    return 0;
}

