#include<stdio.h>

/**
 * 判断单词个数
*/

int main(int argc, char const *argv[])
{
    int count = 0;
    char str[255] = {"I have a Dream"};
    char * p = str;
    while (*p)
    {
        if (*p == ' ')
        {
            count++;
        }
        p++;
    }
    printf("单词个数为%d\n" , count+1);
    return 0;
}
