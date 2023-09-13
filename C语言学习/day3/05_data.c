#include<stdio.h>
int main(int argc, char const *argv[])
{
    //一维数组初始化专题

    //第一种    直接赋值 0      {0}     结果数组内的值全为 0
    int arr_1[10] = {0};
    for (int i = 0; i < 10; i++)
    {
         printf("同学%d 的成绩为 %d\n" , i + 1 , arr_1[i]); 
    }

    //第二种    部分赋值                结果是未初始化的部分补 0
    int arr_2[10] = {1,2,3,4,5,6,7};
    for (int i = 0; i < 10; i++)
    {
         printf("同学%d 的成绩为 %d\n" , i + 1 , arr_1[i]); 
    }

    //第三种    不规定大小              结果是
    int arr_3[] = {1,2,3,4,5,6,7,8,9,0};
    print("%ld\n" , sizeof(arr_3));
    
    return 0;
}
