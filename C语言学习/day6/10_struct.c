#include<stdio.h>
//字节对齐
#pragma pack(2);

typedef struct student{
    char name1;     //一个字节
    char name2;
    char name3;
    int id;         //四个字节
    char name4;
}student;


int main(int argc, char const *argv[])
{
    student stu = {'1' , '2' , '3' , 4 ,'5'};
    printf("%ld\n" , sizeof(student));     //一共12个字节
    return 0;
}
