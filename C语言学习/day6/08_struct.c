#include<stdio.h>

//结构体    自定义类型
//关键字    struct

struct student
{
    char name[255][255];
    int id;
};

//struct student    现在是一种类型 和 int，char 本质上没区别
int main(int argc, char const *argv[])
{

    //结构体赋初值1
    struct student stu1 = {"徐智伟",1};
    //结构体赋初值2
    struct student students[2] = {{"徐智伟" , 1},{"韩兴炼" ,2}};
    //结构体赋初值3
    struct student stu3[10] = {"0" , 0};
    // for (int i = 0; i < 10; i++)
    // {
    //     scanf("%c %d" , stu3[i].name[i][i] , stu3[i].id);
    // }
    // for (int i = 0; i < 10; i++)
    // {
    //     printf("学生名字是：%s , id为：%d\n" , stu3[i].name[i][i] , stu3[i].id);
    // }
    
    //访问
    printf("学生名字是：%s , id为：%d\n" , stu1.name , stu1.id);
    return 0;
}
