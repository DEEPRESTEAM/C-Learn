#include<stdio.h>

//  %p  输出一个地址（以十六进制形式输出指针的值）
//  指针：  是指向一个地址的变量    其本质是变量，存储的是数据是地址
//  %x,%X   以十六进制输出的无符号整型

int main(int argc, char const *argv[])
{
    int num = 3;
    int * p = &num;         //（&）取地址

    printf("%p\n" , p);

    printf("%x\n" , p);    //解引用
    
    *p = 5;
    printf("%d\n" , num);
    return 0;
}
