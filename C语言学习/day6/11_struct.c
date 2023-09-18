#include<stdio.h>

typedef struct student{
    char name[255];
    int id;
}student;


void print_f(student * stu , int lenght){
    for (int i = 0; i < lenght; i++)
    {
        printf("学生名字:%s , 学生id:%d\n" , stu[i].name , stu[i].id);
    }
}

int main(int argc, char const *argv[])
{
    student stu[16] = {{"张老师",1},{"王老师",1},{"罗老师",1},
                        {"陈老师",1},{"徐老师",1},{"韩老师",1},
                        {"樊老师",1},{"左老师",1},{"李老师",1},
                        {"刘老师",1},{"黎老师",1},{"高老师",1},
                        {"陈老师",1},{"邓老师",1},{"胡老师",1},{"孟老师",1}};

    int length = sizeof(stu)/sizeof(student);
    print_f(stu , length);
    return 0;
}
