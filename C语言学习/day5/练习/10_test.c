#include<stdio.h>


int getAge(int num){
    int age;
    if (num == 1)
    {
        //终止条件
        age = 10;
    }else if (num != 1)
    {
        //每个人年龄差为2
        age = getAge(num-1) + 2;

    }
    return age;
    
    
}

int main(int argc, char const *argv[])
{
    int num = 0;
    printf("请输入求第几个人");
    scanf("%d" , &num);
    int age = getAge(num);
    printf("戊的年龄是：%d" , age);
    return 0;
}
