#include<stdio.h>

int main(int argc, char const *argv[])
{
    int arr[2] = {1 , 2};
    char ch[3] = {"ab"};
    char ch1[3] = {"ab"};
    char * ch_p = ch;
    char * ch1_p = ch1;
    int p1 = ch1_p - ch_p;
    printf("%d\n" , p1);
    printf("%p\n" , arr);
    // printf("%p\n" , p1);
    // p1++;
    // printf("%p\n" , p1);
     printf("%p\n" ,ch);
     printf("%p\n" ,ch1);
    return 0;
}
