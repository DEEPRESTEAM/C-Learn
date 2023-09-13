#include<stdio.h>
int main(int argc, char const *argv[])
{


    //在判断条件中  真的条件为非零  假的条件为零
    int num1 = 20;
    int num2 = 30;
    if (num1 > num2)
    {
        printf("num1 大于 num2\n");
    }else{
        printf("num1 小于 num2\n");
    }
    
    return 0;
}