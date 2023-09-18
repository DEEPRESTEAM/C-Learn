#include<stdio.h>



//指针函数本质上是一个函数返回值为指针
//定义类型为指针，返回值为指针
//定义方式为：type * 函数名（[参数列表]）
//type * 是函数的类型  同时是返回值得类型
//函数名([参数列表])
//用途：数据结构初始化的时候，创建动态内存后返回的操作


int * prt_fun()
{
    int num = 10;
    int * prt_retu = &num;
    return prt_retu;
}


int main(int argc, char const *argv[])
{
    int * retu = prt_fun();
    printf("%d\n" ,*retu);
    return 0;
}
