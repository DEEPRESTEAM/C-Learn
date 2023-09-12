#include<stdio.h>
// * 解引用
// & 取地址


int main(int argc, char const *argv[])
{
    int num = 100;
    int * p = &num;
    //int*   ->   int类型的指针 只能指向int类型的变量

    //&num   取地址  取num的首地址
    printf("%p\n" , p);
    //改数据    解引用
    //读数据    解引用
    printf("num = %d\n" , num);
    printf("*p = %d\n" , *p);   //解引用，读操作

    //两次程序的运行，体现了变量的栈空间自动 申请 和 释放

    int arr[10] = {1,2,3,4,5,6,7,8};
    int * arr_p = arr;
    printf("*arr_p = %d\n" , *(arr_p + 1));
    printf("*(arr_p) = %d\n" , *(arr_p++));
    printf("*(arr_p) = %d\n" , *(arr_p++));
    printf("*arr_p = %d\n" , *arr_p);


    return 0;
}
