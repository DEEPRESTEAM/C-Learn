#include<stdio.h>

void hello(){
    printf("hello\n");
}

int main(int argc, char const *argv[])
{
    void (*hello_1)() = hello;
    hello_1();
    return 0;
}


//函数指针      本质是指针      是一个指向函数的指针
//定义方式      int(*p)(int * name , int * passwd) = arr_fun_1;
//              类型相同（*[指针名]）   参数列表相同 = [函数名]
//              在使用的时候可以直接使用指针


//函数指针      本质是指针      是一个指向函数的指针
//定义方式

