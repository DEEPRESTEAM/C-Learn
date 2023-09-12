#include<stdio.h>

//      条件表达式  使用方法
//      条件表达式？表达式1 : 表达式2
//      首先判断 <条件表达式> 是否为真
//      则执行 表达式1
int main(int argc, char const *argv[])
{
    int i = 50l;
    int j = 20;
    int k = i < j ? i : j;
    printf("%d\n" , k);

    int a , b , c;


    return 0;
}
