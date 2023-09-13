#include<stdio.h>
int main(int argc, char const *argv[])
{
    printf("输入你想进入的界面 \n1:欢迎你\n2:不欢迎你\n");
    int num = 0;

    scanf("%d" , &num );
    switch (num){
    case 1:
        printf("欢迎你\n");
        break;
    case 2:
        printf("不欢迎你\n");
        break;
    case 3:
        printf("一般般\n");
        break;
    default:
        printf("不支持其他选项");
        break;
    }
    return 0;
}
