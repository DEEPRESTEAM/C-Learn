#include<stdio.h>
#include<string.h>

//argc参数数量 
//argv参数数组
int main(int argc, char const *argv[])
{
    char name[255] = "小明";
    char passwd[255] = "8";
    if (argc == 3)
    {
        if (!strcmp(argv[1] , name)) {
            if (!strcmp(argv[2] , passwd)) {
                printf("密码正确\n");
            }
        }
        
    }else {
        printf("请输入参数\n");
    }
    
    return 0;
}
