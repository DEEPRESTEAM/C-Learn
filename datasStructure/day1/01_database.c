#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct node
{
    //数据部分  简单类型    -结构体类型 -结构体指针 -void *
    int data; //4个字节
    struct node * next;//指针是可以确定大小的   变量是不能确定大小的    节点不能包含自己的类型 
}node_t;


int main(int argc, char const *argv[])
{
    printf("%ld\n" , sizeof(node_t));
    return 0;
}
