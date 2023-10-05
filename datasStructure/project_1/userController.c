#include "railway.h"

// 用户功能集成



int userController(linklist_t *head, linklist_t *user_t, linklist_flight * flightHead , int count)
{
    int i = 0;
    int ticketNums = 0;
    while (1)
    {
        int num = 0;
        userFunctionMenue(flightHead);
        printf("请输入你想要选择的功能:");
        scanf("%d", &num);
        getchar();
        switch (num)
        {
        case 1:
            printf("输入你所想需要购买票的序号:");
            int num1 = 0;
            scanf("%d", &num1);
            getchar();
            ticketNums = purchaseTickets(num1, user_t, flightHead);
            printf("--------------------------购票成功----------------------------\n");
            sleep(1);
            system("clear");
            break;
        case 2:
            printf("查询航班\n");
            break;
        case 3:
            system("clear");
            userTicketController(head, user_t, ticketNums);

            break;
        case 4:
            system("clear");
            userCentreController(user_t, head);
            break;
        case 5:
            system("clear");
            return 0;
        default:
            printf("错误\n");
            break;
        }
    }
}

// 购票方法，根据前面的序号，来进行购票
int purchaseTickets(int id, linklist_t *user1, linklist_flight * flightHead)
{
    static int num = 0;
    if (user1 == NULL)
    {
        printf("参数错误\n");
        return -1;
    }
    linklist_flight * temp = flightHead->next;
    user_t * tempuser = user1->user;
    while (temp != flightHead)
    {

        if (id == temp->flights->id)
        {
            printf("请选则你的座位号\n");
            char str[MAX] = {0};
            scanf("%s", str);
            getchar();
            // 判断是否有票
            if (temp->flights->tickets > 0)
            {
                /* code */
                // 进行赋值
                tempuser->tick[num].id = temp->flights->id;
                // 座位号
                strcpy(tempuser->tick[num].seatNumber, str);
                // 入口
                strcpy(tempuser->tick[num].entrance, temp->flights->entrance);
                // 出发日期
                strcpy(tempuser->tick[num].date, temp->flights->date);
                // 起始地
                strcpy(tempuser->tick[num].originalPlace, temp->flights->originalPlace);
                // 目的地
                strcpy(tempuser->tick[num].destination, temp->flights->destination);
                // 价格
                tempuser->tick[num].price = temp->flights->price;
                // 票的数量减一
                temp->flights->tickets--;
                num++;
                return num;
            }
            else
            {
                printf("票已售尽");
                return num;
            }
        }
        temp = temp->next;
    }
}

// 打印用户飞机票
void userPrintfTicket(linklist_t *temp, int num)
{
    if (temp == NULL)
    {
        printf("参数错误\n");
        return;
    }
    user_t *temp1 = temp->user;
    printf("-------------------------------------------用户航班票--------------------------------------------------\n");
    for (int i = 0; i < num; i++)
    {
        printf("-------------------------------------------------------------------------------------------------------\n");
        printf("序号：%d  起始地：%s  目的地：%s  起飞时间：%s  入口：%s  座位号：%s  价格：%lf\n", temp1->tick[i].id, temp1->tick[i].originalPlace, temp1->tick[i].destination, temp1->tick[i].date, temp1->tick[i].entrance, temp1->tick[i].seatNumber, temp1->tick[i].price);
    }
}

// 用户中心控制器
int userCentreController(linklist_t *user, linklist_t *head)
{
    while (1)
    {
        int funNum = 0;
        userCentreControllerMenue();
        printf("选择你的功能\n");
        scanf("%d", &funNum);
        switch (funNum)
        {
        case 1:
            userMessage(user);
            break;
        case 2:
            changeUserPasswd(user, head);
            break;
        case 3:
            return bannedUser(head, user);
        case 4:
            system("clear");
            return 0;
        default:
            break;
        }
        sleep(1);
        system("clear");
    }
    
    
}

/// @brief 查看和修改个人信息
/// @param user
void userMessage(linklist_t *user)
{
    char name[MAX] = {0};
    long int phone = 0;
    int changeNum = 0;
    user_t *temp = user->user;
    printf("姓名：%s  电话：%ld  uid：%d", temp->name, temp->phone, temp->uid);
    while (1)
    {
        printf("是否修改个人信息1/0\n");
        scanf("%d", &changeNum);
        if (changeNum == 0)
        {
            return;
        }
        if (changeNum == 1)
        {
            printf("请输入你所修改的值(只能修改姓名和电话 空格隔开):");
            scanf("%s %ld", name, &phone);
            strcpy(temp->name, name);
            temp->phone = phone;
            break;
        }
        else
        {
            printf("输入错误请重新输入\n");
            continue;
        }
    }
}

// 修改用户密码
void changeUserPasswd(linklist_t *user, linklist_t *head)
{
    if (user == NULL)
    {
        printf("参数错误\n");
        return;
    }
    user_t *temp = user->user;
    user_t user1 = {0};
    userChangePsaawd(head, &user1);
}

// 注销用户（注销后会直接回到登录页面）
int bannedUser(linklist_t *head, linklist_t *users)
{
    int i = 1;
    if (head == NULL || head->next == head || users == NULL)
    {
        printf("参数错误\n");
        return -1;
    }
    linklist_t *temp = head->next;
    while (temp != head)
    {
        while (i)
        {
            if (temp->user->id == users->user->id)
            {
                // 将节点与链表断开
                temp->pre->next = temp->next;
                temp->next->pre = temp->pre;
                // 释放user节点的空间
                free(temp->user);
                temp->user = NULL;
                // 释放temp的空间
                free(temp);
                i = 0;
            }
            break;
        }
        // 如果找到用户id号，进行删除操作
        temp->next->user->id--;
        temp = temp->next;
    }
    return 1;
}

// 用户查询航班
void findFlight(linklist_t *head)
{
}

// 用户票券模块
int userTicketController(linklist_t * head , linklist_t *user_t, int ticketNums)
{
    int funNum = 0;
    while (1)
    {
        userTicketControllerMenue();
        printf("输入你想要的功能序号:");
        scanf("%d", &funNum);
        getchar();
        switch (funNum)
        {
        case 1:
            userPrintfTicket(user_t, ticketNums);
            break;
        case 2:
            //userReturnTicket();
            break;
        case 3:
            printf("用户改签\n");
            break;
        case 4:
            system("clear");
            return 0;
        default:
            break;
        }
    }
}

// 用户退票
void userReturnTicket(linklist_t *head, linklist_t *temp, int num)
{
    int retNum = 0;
    int flag = 0;
    printf("输入所退票的序号");
    scanf("%d" , &retNum);
    getchar();
    printf("是否退票(0|1)");
    scanf("%d" , &flag);
    getchar();

    if (flag == 0)
    {
        return;
    }else{

    }
    
}
