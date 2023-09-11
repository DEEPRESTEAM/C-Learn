#include<stdio.h>
#define Sum i+j


int sum(int i , int j){
    int sum = i + j;
    return sum;
}
int main()
{
    int i = 5;
    int j = 6;
    int Sum_1;
    int sum_1 = sum(i , j);
    Sum_1 = Sum * 6;
    printf("%d\n",Sum_1);
    printf("%d\n",sum_1);
    return 0;
}

