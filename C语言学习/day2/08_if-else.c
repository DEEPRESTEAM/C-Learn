#include<stdio.h>
#define NAME 2308
#define PASSWD 2308
//1、当你的程序比较大时
//2、该数据不会变动
//3、在很多地方能够用到
//当很多

//  if      判断        分支        语句
int main(int argc, char const *argv[])
{
    int name = NAME;
    int passwd = PASSWD;

    int user_name = 0;
    int user_passwd = 0;
    char ch = 0;

    printf("请输入你的账号:\n");
    scanf("%d" , &user_name);
    getchar();
    printf("请输入你的密码:\n");
    scanf("%d" , &user_passwd);
    getchar();

    // if (user_name == name)
    // {
    //     printf("你的账号正确\n");
    //     ch++;
    // }else{
    //     printf("你的账号错误");
    //     return -1;
    // }

    // if (user_passwd == passwd)
    // {
    //     printf("你的密码正确\n");
    //     ch++;
    // }else{
    //     printf("你的密码错误");
    //     return -1;
    // }

    // if (ch == 2)
    // {
    //     printf("欢迎进入系统\n");
    // }

    if (user_name == name)
    {
        if (user_passwd == passwd)
        {
            printf("欢迎进入系统\n");
            return -1;
        }
        printf("你的密码错误\n");
        return -1;
    }
    printf("你的账号错误\n");
    
    
    
    return 0;
}
