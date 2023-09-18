#include<stdio.h>
//指针数组      相同类型的指针
//  是一个数组      数组内部存放的是地址
//数组指针（重点）
//  是一个指针      指针指向的是一个数组
//  定义：
//      int （*指针名） = arr 指向一维数组
//      int  (*指针名)[] = arr; 指向二维数组
int main(int argc, char const *argv[])
{
    char name[5][9] = {
        "韩兴炼",
        "徐智炜",
        "陈宝龙"
    };
    //定义一个数组指针
    char (*name_p)[10] = name;
    printf("%s\n" , name_p[1]);

    //定义一个指针数组
    // int *arr[10] = {NULL};
    // int num[10] = {1,2,3,4,5,6,7,8,9,10};
    // arr[0] = num;
    // int num_1[3][3] = {1,2,3,4,5,6,7,8,9};

    // int (*p)[3] = num_1;
    // arr[1] = p[0];  
    // printf("%d\n" , (arr[1]+1)[2]);
    // printf("%p\n" , arr[0]);
    // printf("%d\n" , arr[0][5]);
    //printf("%d\n" , num_1[0][6]);
    return 0;
}
