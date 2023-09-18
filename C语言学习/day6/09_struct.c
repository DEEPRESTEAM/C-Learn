#include<stdio.h>

//做普通的定义
//stu1 , stu2  直接定义
struct student
{
    char name[255];
    int id;                                                                                                                                                                                                                                                                                                                                                                                                                                                     
}stu1 , stu2;

//typedef进行定义
//作用重命名变量
typedef struct student_1
{
    char name[255];
    int id;
}student_1;



int main(int argc, char const *argv[])
{
    student_1 stu1 = {"0",0};
    return 0;
}
