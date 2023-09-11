#include<stdio.h>

void menu(char name[] , char sex[] , int age , int phone , float height){
    printf("**********************\n");
    printf("*         名片       *\n");
    printf("******************************\n");
    printf("*         姓名:%s        *\n" , name);
    printf("*         性别:%s            *\n" , sex);
    printf("*         年龄:%d            *\n" , age);
    printf("*         电话:%d          *\n" , phone);
    printf("*         身高:%f    *\n" , height);
}

int main(int argc, char const *argv[])
{
    char name[100] = {0};
    char sex[20] = {0};
    int age , phone;
    float height; 
    printf("输入你的姓名：");
    scanf("%s" , name);
    getchar();
    printf("输入你的性别：");
    scanf("%s" , sex);
    getchar();
    printf("输入你的年龄：");
    scanf("%d" , &age);
    getchar();
    printf("输入你的电话：");
    scanf("%d" , &phone);
    getchar();
    printf("输入你的身高：");
    scanf("%f" , &height);
    getchar();
    menu(name , sex , age , phone , height);
    return 0;
}
