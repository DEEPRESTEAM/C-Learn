#include<stdio.h>

#define PI 3.14159
//  常量在完成之后不能修改
//  无脑替换
//  define 常量不允许不赋初值
//  const：常量修饰符
int main(int argc, char const *argv[])
{
    const int pi = 3 ;
    printf("%d\n" , pi);

    const int num;
    printf("%d\n" , num);   

    //可以运行，在没赋初值的情况下会默认赋初值，但是const修饰常量时一定要赋初值

    return 0;
}
