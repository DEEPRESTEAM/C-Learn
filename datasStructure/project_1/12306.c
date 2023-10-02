#include "railway.h"
#if 0
//管理员用户
typedef struct Admins
{
    int id;                     //id自增
    int uid;                    //账户id自增
    int accountNumber;          //账户号
    char passwd[MAX];           //密码
    long int phone;             //电话号码
    int jurisdiction;           //账号权限 
    unsigned long long int idNumber;     //身份证号
    char name[MAX];             //姓名
    room rooms[MAX];            //大厅显示内容
    
}admins;
#endif

// 登陆界面
void showMenu()
{
    printf("------------------------------\n");
    printf("|   登陆航班系统              |\n");
    printf("------------------------------\n");
    printf("|    1：注册                 |\n");
    printf("|    2：登录                 |\n");
    printf("|    3：忘记密码             |\n");
    printf("|    4：退出系统             |\n");
    printf("------------------------------\n");
}


//用户功能选择页面
void userFunctionMenue(linklist_t * head , int count){
    printf("--------------------主界面--------------------\n");
    printf("航班信息\n");
    userFlightPrintf(head , count);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("------------------用户功能界面-----------------\n");
    printf("|                 1:购票窗口                  |\n");
    printf("|                 2:查询航班                  |\n");
    printf("|                 3:本人票券                  |\n");
    printf("|                 4:用户中心                  |\n");
    printf("|                 5:返回上一级                |\n");
    printf("----------------------------------------------\n");
}

//用户中心共能选择界面
void userCentreControllerMenue(){
    printf("---------------欢迎来到用户中心--------------\n");
    printf("|              1:个人信息管理                 | \n");
    printf("|              2:修改密码                     |\n");
    printf("|              3:注销用户                     |\n");
    printf("|              4:返回上一级                   |\n");
    printf("-----------------------------------------------\n");
}

//管理员功能选择界面
void adminControllerMenue(){
    printf("---------------欢迎来到管理员中心--------------\n");
    printf("|              1:个人信息管理                 | \n");
    printf("|              2:修改密码                     |\n");
    printf("|              3:注销用户                     |\n");
    printf("|              4:返回上一级                   |\n");
    printf("-----------------------------------------------\n");
}

// 管理员功能选择界面
void userTicketControllerMenue()
{
    printf("-----------------用户票券中心---------------\n");
    printf("|              1:用户票券                 | \n");
    printf("|              2:退票                     |\n");
    printf("|              3:改签                     |\n");
    printf("|              4:返回上一级                |\n");
    printf("--------------------------------------------\n");
}

// 用户登录
linklist_t * login(linklist_t *head, user_t *user)
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
    scanf("%lld" , &user->idNumber);
    getchar();
    printf("输入你的姓名:");
    scanf("%s" , user->name);
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
    int num = 0;
    // 验证用户账户
    printf("请输入你的账户:");
    scanf("%d", &num);
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

// 登录功能集成
linklist_t * loginIntegration(linklist_t *head, user_t *user, int size)
{
    int temp = 0;
    int flag = 0;
    int flag_while = 1;
    linklist_t * temp_lin = NULL;
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
            }else if (temp == -1)
            {
                printf("注册失败\n");
            }else if (temp == -2)
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

// 双向链表的头节点的创建
linklist_t *
creatHeadNode()
{
    linklist_t *head = malloc(sizeof(linklist_t));
    head->user = malloc(sizeof(user_t));
    if (head == NULL || head->user == NULL)
    {
        printf("申请空间失败\n");
        return NULL;
    }
    head->user->id = 0;
    head->user->uid = 100000;
    head->pre = head->next = head;
    return head;
}

/// @brief 判断头节点是否创建成功
/// @param head  传入刚创建的头节点
/// @return 创建失败返回 -1 成功返回 0；
int judgetHeadIsNull(linklist_t *head)
{
    if (head == NULL)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

/// @brief 双向循环链表的尾插法
/// @param head 传入链表头节点
/// @param user 传入用户数据
/// @param size 用户数据大小
/// @return
int insertTailNewNode(linklist_t *head, user_t *user, int size)
{
    int id = 0;
    int uid = 0;
    if (head == NULL)
    {
        printf("链表不存在\n");
        return -1;
    }
    if (user == NULL)
    {
        printf("传入参数错误\n");
        return -1;
    }
    // 找到需要插入的位置
    linklist_t *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    // 获取插入前位置的id与uid值
    id = temp->user->id;
    uid = temp->user->uid;
    // 在前一个值的情况下自增
    user->id = ++id;
    user->uid = ++uid;
    linklist_t *newNode = malloc(sizeof(linklist_t));
    newNode->user = malloc(size);
    if (newNode == NULL || newNode->user == NULL)
    {
        printf("分配空间失败\n");
        return -1;
    }
    memcpy(newNode->user, user, size);

    newNode->next = temp->next;
    newNode->pre = temp;
    temp->next = newNode;
    head->pre = newNode;
    return 0;
}

/// @brief 插入数据（双向1的头插法）
/// @param head 传入双向链表的头节点
/// @param user 传入创建用户信息
void insertHeadToLinklist(linklist_t *head, user_t user)
{
    if (head == NULL)
    {
        printf("linklist is illage\n");
        return;
    }
    linklist_t *newNode = malloc(sizeof(linklist_t));
    linklist_t *temp = head;
}

/// @brief 双向链表的遍历
/// @param head 传入头节点
void linkListPrintf(linklist_t *head)
{
    if (head == NULL || head->next == NULL)
    {
        printf("链表为空\n");
        return;
    }
    linklist_t *temp = head->next;
    // 从前往后进行遍历
    while (temp != head)
    {
        printf("%ld %s\n", temp->user->accountNumber,  temp->user->passwd);
        // printf("id = %d uid = %d accountNumber = %ld passwd = %s phone = %ld jurisdiction = %d idNumber = %lld name = %s \n" , temp->user->id , temp->user->uid , temp->user->accountNumber , temp->user->passwd , temp->user->phone , temp->user->jurisdiction , temp->user->idNumber , temp->user->name);
        temp = temp->next;
    }
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

/// @brief 从文件中读取文件到链表中
/// @param head 传入链表的头节点
/// @param file 传入文件的路径
/// @param size 传入读取文件结构体的大小
/// @return 成功返回读取的数量
int getgetFileToLinklist(linklist_t *head, FILE *file, int size)
{
    if (head == NULL || file == NULL)
    {
        printf("链表为空无法读取或文件打开失败\n");
        return -1;
    }
    // 文件读取内容默认使用尾插法读取
    int flag = 1;
    int count = 0;
    linklist_t *temp = head;
    while (flag)
    {
        linklist_t *newNode = malloc(sizeof(linklist_t));
        newNode->user = malloc(size);
        flag = fscanf(file, "%d %d %ld %s %ld %d %lld %s", &newNode->user->id, &newNode->user->uid, &newNode->user->accountNumber, newNode->user->passwd, &newNode->user->phone, &newNode->user->jurisdiction, &newNode->user->idNumber, newNode->user->name);
        if (flag == EOF)
        {
            free(newNode->user);
            free(newNode);
            break;
        }
        count++;
        if (newNode == NULL || newNode->user == NULL)
        {
            printf("新节点空间分配失败\n");
            return -1;
        }
        while (temp->next != head)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->pre = temp;
        temp->next = newNode;
        head->pre = newNode;
    }
    return count;
}

// 打开文件
FILE *file_open(char *file_name, char *modes)
{
    FILE *fp = fopen(file_name, modes);
    if (fp == NULL)
    {
        printf("打开文件失败\n");
        fclose(fp);
        return NULL;
    }
    return fp;
}


//将航班信息写入到每个客户节点中
int readFlightToUserNode(linklist_t * head , FILE * file){
    int count = 0;
    int flag = 1;
    if (head == NULL || head->next == NULL)
    {
        printf("链表为空或数据为空\n");
        return -1;
    }
    linklist_t * temp = head;
    int result = 0;
    count = 0;
    while (flag)
    {
        result =fscanf(file , "%d %s %s %s %s %d %lf" , &temp->user->flight[count].id , temp->user->flight[count].originalPlace , temp->user->flight[count].destination , temp->user->flight[count].date , temp->user->flight[count].entrance  , &temp->user->flight[count].tickets , &temp->user->flight[count].price);
        count++;
        if (result == EOF)
        {
            rewind(file);
            break;
        }
    }    
    printf("读写完成\n");
    
    return count;
}

/// @brief 打印存储在用户信息中的航班信息
/// @param head 传入链表的头节点
/// @param count 返回打印的次数
void userFlightPrintf(linklist_t * head , int count){
    if (head == NULL || head->next == NULL)
    {
        printf("参数错误\n");
        return;
    }
    linklist_t * temp = head;
    for (int i = 0; i < count - 1; i++)
    {
        printf("序号：%d  起始地：%s  目的地：%s  起飞时间：%s  入口：%s  票量：%d  价格：%lf\n" ,temp->user->flight[i].id , temp->user->flight[i].originalPlace , temp->user->flight[i].destination , temp->user->flight[i].date , temp->user->flight[i].entrance , temp->user->flight[i].tickets , temp->user->flight[i].price);
    }
}