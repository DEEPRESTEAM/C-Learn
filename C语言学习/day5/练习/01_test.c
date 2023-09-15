#include<stdio.h>

/**
 * 小猪过河问题
*/

int main(int argc, char const *argv[])
{
    int pigNum[10] = {0};
    int count = 0;
    printf("会划船的猪每次都能带两只猪过河\n");
    printf("请输入需要带多少只小猪过河\n");
    scanf("%d" , pigNum);
    getchar();
    int * p = NULL;
    p = pigNum;
    while (*p)
    {
        if ((*p - 1) % 2 == 0)
        {
            *p = (*p - 1)/2;
        }else {
            *p = (*p -1)/2 + 1;
        }
        p++;
    }
    p = p - 1;
    printf("因此需要 %d 次才能过河\n" , *p);
    return 0;
}
