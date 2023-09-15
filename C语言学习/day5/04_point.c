#include<stdio.h>

int main(int argc, char const *argv[])
{
    int arr[11] = {1,2,3,4,5,6,7,8,9,10};
    char ar[2] = 0;
    int * p = arr;
    // while (*p)
    // {
    //     printf("arr= %d\n",*p);
    //     arr++;
    //     ar++;
    // } 
    return 0;
}


void add(int a[10]){
    while (*a)
    {

        a++;
    }
    
}