#include<stdio.h>
int main(int argc, char const *argv[])
{
    int arr[3] = {1,2,3};
    //数组在定义时 就确定好地址了 这个地址可以变动，但是有范围，只能在自己创建空间内移动
    
    //实验一：尝试用同样的操作方式对数组和指针进行操作
    //实验二：尝试对数组名进行赋值
    int * p = arr;
    printf("%p\n" , arr);
    printf("%d\n" , *(arr+1));
    printf("%d\n" , arr[2]);

    printf("%p\n" , p);
    printf("%d\n" , *(p+1));
    printf("%d\n" , p[2]);
    return 0;
}
