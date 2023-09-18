#include<stdio.h>

//共用体中，占内存大小是随内部最大变量来的
//空间共用
//
typedef union stu_un
{
    int i;
    double dou;
}stu_un_1;


//关于共用体赋值的问题
//1.前后顺序
/**
 * 最后一个变量会对他所属的这片空间重新赋值
 * 
*/
int main(int argc, char const *argv[])
{
    stu_un_1 stu;
    stu.dou = 3.141;
    stu.i = 12345;
    printf("%d\n" , stu.i);
    printf("%lf\n" , stu.dou);
    return 0;
}
