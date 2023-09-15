#include<stdio.h>

/**
 * 电影院售票情况
*/
int main(int argc, char const *argv[])
{
    int count = 0;
    int num[4][4] = {0};
    printf("输入电影院的售票情况\n");
    for (int i = 0; i < sizeof(num[i])/sizeof(int); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%d" , &num[i][j]);
            getchar();
        }
        
    }
    int * p = num[0];
    for (int i = 0; i < 16; i++)
    {
        if (*p == 1)
        {
            count++;
        }
        p++;
    }
    printf("剩余的票是：%d\n" , count);
    return 0;
}