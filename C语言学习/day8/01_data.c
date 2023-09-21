#include<stdio.h>
#include<stdlib.h>

// 申请空间
// void * 类型      泛指针      可以转换其他类型的
// extern void *malloc (size_t __size)
// size_t __size     需要申请空间的大小
// malloc
//强制类型转换 (type *)malloc(sizeof(type));

// 释放空间
// extern void free (void *__ptr)
// free(__ptr) 
typedef struct xzw
{
    char * name;
    int id;
} xzw;



int main(int argc, char const *argv[])
{
    //申请空间
    xzw * xzw1 = (xzw *)malloc(sizeof(xzw));
    xzw1->id = 1;
    xzw1->name = "徐智伟";
    printf("%s\n" , xzw1->name);
    xzw1->name = "李昊霖";
    printf("%s\n" , xzw1->name);



    //释放空间
    free(xzw1);
    return 0;
}
