#include"railway.h"

// 登录功能集成


linklist_t *loginIntegration(linklist_t *head, user_t *user, int size)
{
    int temp = 0;
    int flag = 0;
    int flag_while = 1;
    linklist_t *temp_lin = NULL;
    while (flag_while)
    {
        printf("请输入功能:");
        scanf("%d", &flag);
        getchar();
        switch (flag)
        {
        case 1:
            temp = regist(head, user, size);
            if (temp == 0)
            {
                printf("注册成功\n");
            }
            else if (temp == -1)
            {
                printf("注册失败\n");
            }
            else if (temp == -2)
            {
                printf("账户已存在\n");
            }
            break;
        case 2:
            temp_lin = login(head, user);
            return temp_lin;
        case 3:
            userChangePsaawd(head, user);
            break;
        case 4:
            flag_while = 0;
            printf("退出成功\n");
            break;
        default:
            printf("输入的序号错误\n");
            break;
        }
    }
    return NULL;
}

// 用户登录
linklist_t *login(linklist_t *head, user_t *user)
{
    int flag = 0;
    linklist_t *temp = NULL;
    while (1)
    {
        printf("请输入你的账号:");
        scanf("%ld", &user->accountNumber);
        printf("请输入你的密码:");
        scanf("%s", user->passwd);
        getchar();
        if (flag == 6)
        {
            printf("输入次数过多强制退出\n");
            return NULL;
        }
        temp = loginCheck(head, user);
        if (temp == NULL)
        {
            printf("账户或密码错误\n");
            flag++;
            continue;
        }
        else
        {
            break;
        }
    }
    return temp;
}

/// @brief 登录验证
/// @param head 传入链表头节点
/// @param data 传入需要验证的数据
/// @return 返回验证成功的变量
linklist_t *loginCheck(linklist_t *head, user_t *data)
{
    if (head == NULL || head->next == NULL)
    {
        printf("链表为空或不存在\n");
        return NULL;
    }
    if (data == NULL)
    {
        printf("参数cuowu\n");
        return NULL;
    }
    linklist_t *temp = head->next;
    while (temp != head)
    {
        if (temp->user->accountNumber == data->accountNumber)
        {
            if (!strcmp(temp->user->passwd, data->passwd))
            {
                return temp;
            }
        }
        temp = temp->next;
    }
    if (temp == head)
    {
        return NULL;
    }
}

// 用户注册
int regist(linklist_t *head, user_t *user, int size)
{
    printf("输入电话号码:");
    scanf("%ld", &user->phone);
    getchar();
    printf("输入密码:");
    scanf("%s", user->passwd);
    getchar();
    printf("输入身份证号码:");
    scanf("%lld", &user->idNumber);
    getchar();
    printf("输入你的姓名:");
    scanf("%s", user->name);
    getchar();
    user->accountNumber = user->phone;
    user->jurisdiction = 0;
    linklist_t *temp = head->next;
    while (temp != head)
    {
        if (temp->user->accountNumber == user->accountNumber)
        {
            return -2;
        }
        temp = temp->next;
    }

    if (!insertTailNewNode(head, user, size))
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

// 用户忘记密码（验证成功修改密码）
void userChangePsaawd(linklist_t *head, user_t *user)
{
    if (head == NULL || head->next == head || user == NULL)
    {
        printf("参数错误\n");
        return;
    }
    linklist_t *temp = head->next;
    // 验证用户账户
    printf("请输入你的账户:");
    scanf("%ld", &user->accountNumber);
    getchar();
    while (temp != head)
    {

        if (temp->user->accountNumber == user->accountNumber)
        {
            while (1)
            {
                printf("请输入你的身份证号与姓名(中间用空格隔开):");
                scanf("%lld %s", &user->idNumber, user->name);
                getchar();
                // 验证用户信息
                if (temp->user->idNumber == user->idNumber && !strcmp(temp->user->name, user->name))
                {
                    while (1)
                    {
                        user_t user1 = {0};
                        printf("填写新的密码:");
                        scanf("%s", user->passwd);
                        getchar();
                        printf("再次填写新密码:");
                        scanf("%s", user1.passwd);
                        getchar();
                        if (!strcmp(user->passwd, user1.passwd))
                        {
                            strcpy(temp->user->passwd, user1.passwd);
                            printf("修改成功\n");
                            return;
                        }
                        else
                        {
                            printf("两次输入密码不一致，请重新输入\n");
                            continue;
                        }
                    }
                }
                else
                {
                    printf("用户信息错误，是否重新输入（1/0）\n");
                    int flag = 0;
                    scanf("%d", &flag);
                    getchar();
                    if (flag == 1)
                    {
                        continue;
                    }
                    else if (flag == 0)
                    {
                        printf("退出忘记密码系统\n");
                        return;
                    }
                }
            }
        }
        temp = temp->next;
    }
    if (temp == head)
    {
        printf("用户不存在\n");
    }
}

