#include<stdio.h>
#include<string.h>

/**
 * 登录判断
*/
void judgement( char NAME[] , char PASS[] , char userName[] , char userPasswad[]){
    int count = 0;
    while (1)
    {                        
        printf("请输入你的账号：");
        scanf("%s" , NAME);
        getchar();
        if (!strcmp(NAME , userName))
        {
            while (1)
            {
                printf("用户名正确，请输入密码：");
                scanf("%s" , PASS);
                getchar();
                if (!strcmp(PASS , userPasswad))
                {
                    printf("密码正确，欢迎");
                    return;
                }else {
                    printf("密码错误请重新输入密码：\n");
                }
            }
        }else{
            printf("账户错误，请重新输入：\n");
        }
    }
}


/**
 * 串口判断
*/
void serialPortResponse(char buf[] , char bufReply[]){
    printf("你进入到模拟串口回访\n");
    while (1)
    {
        printf("输入你所需要访问的串口\n");
        scanf("%s" , buf);
        getchar();
        if (strlen(buf) > 20)
        {
            printf("你输入的长度越界请重新输入");
            continue;
        }
        strcpy(bufReply , buf);
        printf("串口回应：%s\n" , bufReply);
        break;
    }
}

/**
 * 链接函数
*/
void link(char yesOrNo[] , char yes[] , char buf[] , char bufReply[]){
    printf("接下来是我们的连接：\n");
    printf("这个需要你的同意，输入yes为同意，输入no为不同意");
    scanf("%s" , yesOrNo);
    getchar();//吸收\n吸收缓存区
    if (!strcmp(yes , yesOrNo))
    {
        strcat(bufReply , buf);
        printf("链接后的字符串%s\n" , bufReply);
    }
}

void find(char findChar[]){
    printf("欢迎来到查找功能，你可以输入一个字符  我们2308团队来帮你找到这个字符\n");
    printf("%s\n" , findChar);
    printf("输入你需要查找的字符(仅需输入一个)\n");
    char c = getchar();
    char * chp = strchr(findChar , c);
    if(chp != NULL)
    {
        printf("找到了，后面的值为：%s\n" , chp);    
    }else
    {
        printf("抱歉没找到这个字符\n");
    }
}


int main(int argc, char const *argv[])
{
    //定义账户与密码
    char usreName[20] = "2308_hqyj";
    char userPasswad[20] = "2308_hqyj";
    //定义字符串    
    char NAME[20] = "";
    char PASS[20] = "";
    //定义回复消息数组
    char buf[20] = "";
    char bufReply[20] = "";
    //连接同意字符数字
    char yes[5] = "yes";
    char yesOrNo[5] = "";

    //被查找的字符串
    char bookStr[225] = {"gahjsdghjagsdhjadhjasd"};
    find(bookStr);


    /**
     * 登陆判断
    */
    judgement( NAME , PASS , usreName , userPasswad);

    /**
     * 串口判断
    */
    serialPortResponse(buf , bufReply);

    /**
     * 连接
    */
    link(yesOrNo , yes , buf , bufReply);

    
    
    return 0;
}
