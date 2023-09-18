#include<stdio.h>
/**
 * 用户修改账号和密码
*/
void changeUserNameAndUserPassd(int * userName , int * userPassd){
    int userId = 0;
    int flag = 0;
    printf("输入你想要修改的账号:");
    scanf("%d" , &userId);
    getchar();
    while (*userName)
    {
        if (*userName == userId) {
            printf("输入你想要修改的密码:");
            scanf("%d" , userPassd);
            getchar();
            printf("修改成功\n");
            break;
        }
        if (*(userName+1) == 0)
        {
            printf("没有此账户或账户输入错误\n");
            break;
        }
        userName++;
        userPassd++;
        
    }

}

void login(int * userName , int * userPasswd){
    int name = 0;
    int passwd = 0;
    int * n = userName;
    int * p = userPasswd;
    int count = 0;
    while (1)
    {
        /* code */
    }
    
    printf("输入账户:");
    scanf("%d" , &name);
    getchar();
    printf("输入密码:");
    scanf("%d" , &passwd);
    while (*n == 0 && *p == 0)
    {
       
        if (*n == name && *p == passwd)
        {
            printf("成功登录\n");
            break;
        }else {
            printf("账户或者密码错误\n");
            continue;
        }
        n++;
        p++;
        count++;
    }
    
}


int main(int argc, char const *argv[])
{
    int userName[10] = {1001 , 1002 , 1003 , 1004 , 1005};
    int userPasswd[10]  ={1001 , 1002 , 1003 , 1004 , 1005};
    changeUserNameAndUserPassd(userName , userPasswd);
    int * n = userName;
    int * p = userPasswd;
    while (*n != 0 || *p !=0)
    {
        printf("账户:%d\n" , *n);
        printf("密码:%d\n" , *p);
        n++;
        p++;
    }
    return 0;
}
