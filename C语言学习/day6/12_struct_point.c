#include<stdio.h>
#include<string.h>
//结构体指针
typedef struct student{
    char name[255];
    int id;
}student;



int main(int argc, char const *argv[])
{
    student stu = {"小明" , 2};

    //结构体指针
    student * stu_point = &stu;
    //访问结构体指针    引用方式    不用解引用
    stu_point->id = 50;
    strcpy(stu_point->name , "小王");
    printf("姓名:%s , 学号:%d\n" , stu_point->name , stu_point->id);
    return 0;
}
