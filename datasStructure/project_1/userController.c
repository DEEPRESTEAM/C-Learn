#include "railway.h"

// 用户功能集成

int userController(linklist_t *head, linklist_t *user_t, linklist_flight *flightHead)
{
    int i = 0;
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
            purchaseTickets(num1, user_t, flightHead);
            printf("--------------------------购票成功----------------------------\n");
            sleep(1);
            system("clear");
            break;
        case 2:
            printf("查询航班\n");
            break;
        case 3:
            system("clear");
            i = userTicketController(head, user_t, flightHead);
            if (i == -1)
            {
                return -1;
            }
            break;
        case 4:
            system("clear");
            if (userCentreController(user_t, head) == -1)
            {
                return -1;
            }
            break;
        case 5:
            // 返回上一级
            system("clear");
            return 0;
        default:
            printf("错误\n");
            break;
        }
    }
}

// 购票方法，根据前面的序号，来进行购票
int purchaseTickets(int id, linklist_t *user1, linklist_flight *flightHead)
{
    if (user1 == NULL || user1->user == NULL || user1->user->ticketHead == NULL || flightHead == NULL)
    {
        printf("参数错误\n");
        return -1;
    }
    int count = 0;
    //序号自增删除不可控
    linklist_ticket * tempNode = user1->user->ticketHead;
    if (tempNode->next != user1->user->ticketHead)
    {
        while (tempNode->next != user1->user->ticketHead)
        {
            count++;
            tempNode = tempNode->next;
        }
    }
    linklist_ticket *newNode = NULL;
    linklist_ticket *tempTicketHead = user1->user->ticketHead;
    static int num = 0;
    linklist_flight *temp = flightHead->next;
    user_t *tempuser = user1->user;

    // 票券链表分配空间
    newNode = malloc(sizeof(linklist_ticket));
    newNode->ticket = malloc(sizeof(ticket_t));
    if (newNode == NULL || newNode->ticket == NULL)
    {
        printf("申请空间失败\n");
        return -2;
    }
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
                newNode->ticket->id = temp->flights->id;
                // 座位号
                strcpy(newNode->ticket->seatNumber, str);
                // 入口
                strcpy(newNode->ticket->entrance, temp->flights->entrance);
                // 出发日期
                strcpy(newNode->ticket->date, temp->flights->date);
                // 起始地
                strcpy(newNode->ticket->originalPlace, temp->flights->originalPlace);
                // 目的地
                strcpy(newNode->ticket->destination, temp->flights->destination);
                // 价格
                newNode->ticket->price = temp->flights->price;
                // 票的数量减一
                temp->flights->tickets--;
                // 序号自增
                newNode->ticket->uid = count+1;
                num++;
            }
            else
            {
                printf("票已售尽");
            }
        }
        temp = temp->next;
    }

    //找到链表的最后一位
    while (tempTicketHead->next != user1->user->ticketHead)
    {
        tempTicketHead = tempTicketHead->next;
    }
    // 链表连接
    newNode->next = tempTicketHead->next;
    newNode->pre = tempTicketHead;
    tempTicketHead->next = newNode;
    // 头节点
    user1->user->ticketHead->pre = newNode;
}

// 打印用户飞机票
void userPrintfTicket(linklist_t *node)
{
    if (node->user->ticketHead->next == node->user->ticketHead)
    {
        printf("没有车票\n");
        return;
    }
    linklist_ticket *tempTicketHead = node->user->ticketHead->next;
    printf("-------------------------------------------用户航班票--------------------------------------------------\n");
    while (tempTicketHead != node->user->ticketHead)
    {
        printf("-------------------------------------------------------------------------------------------------------\n");
        printf("编号：%d  航班序号：%d  起始地：%s  目的地：%s  起飞时间：%s  入口：%s  座位号：%s  价格：%lf\n", tempTicketHead->ticket->uid, tempTicketHead->ticket->id, tempTicketHead->ticket->originalPlace, tempTicketHead->ticket->destination, tempTicketHead->ticket->date, tempTicketHead->ticket->entrance, tempTicketHead->ticket->seatNumber, tempTicketHead->ticket->price);
        tempTicketHead = tempTicketHead->next;
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
    if (head == NULL || head->next == head || users == NULL)
    {
        printf("参数错误\n");
        return -1;
    }
    linklist_t *temp = head->next;
    linklist_t *temp1 = NULL;
    while (temp != head)
    {

        if (temp->user->id == users->user->id)
        {
            temp1 = temp;
            // 将节点与链表断开
            while (temp1 != head)
            {
                // 如果找到用户id号，进行删除操作
                temp1->next->user->id--;
                temp1 = temp1->next;
            }
            temp->pre->next = temp->next;
            temp->next->pre = temp->pre;
            // 释放user节点中ticket的空间
            deleteTicketLinklist(&(temp->user->ticketHead));
            // 打印tick链表
            // userPrintfTicket(users);
            //  释放user节点的空间
            free(temp->user);
            temp->user = NULL;
            // 释放temp的空间
            free(temp);
            temp = NULL;
            return -1;
        }
        temp = temp->next;
    }
}

// 用户查询航班
void findFlight(linklist_t *head)
{
}

// 用户票券模块
int userTicketController(linklist_t *head, linklist_t *userNode, linklist_flight *flightHead)
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
            userPrintfTicket(userNode);
            break;
        case 2:
            userReturnTicket(userNode, flightHead);
            break;
        case 3:
            userChangeTicket(flightHead, userNode);
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
void userReturnTicket(linklist_t *userNode, linklist_flight *flightHead)
{
    printf("-------------------------------------------用户退票-------------------------------------------\n");
    userPrintfTicket(userNode);
    if (userNode == NULL)
    {
        printf("参数错误\n");
        return;
    }
    if (userNode->user->ticketHead->next == userNode->user->ticketHead)
    {
        printf("抱歉没有飞机票可退\n");
        return;
    }

    int retNum = 0;
    int flag = 0;
    // 航班编号用于暂存
    int flightid = 0;
    printf("输入所退票的编号");
    scanf("%d", &retNum);
    getchar();
    printf("是否退票(0|1)");
    scanf("%d", &flag);
    getchar();
    if (flag == 0)
    {
        return;
    }
    else
    {
        linklist_ticket *temp = userNode->user->ticketHead->next;
        linklist_ticket * temp_next = NULL;
        while (temp != userNode->user->ticketHead)
        {
            if (retNum == temp->ticket->uid)
            {
                if (temp->next != userNode->user->ticketHead)
                {
                    temp_next = temp->next;
                    flag = 2;
                }
                // 航班编号赋值
                flightid = temp->ticket->id;
                // 删除链表节点
                temp->next->pre = temp->pre;
                temp->pre->next = temp->next;
                free(temp->ticket);
                temp->ticket = NULL;
                free(temp);
                temp = NULL;
                break;
            }

            temp = temp->next;
        }
        linklist_flight *tempFlight = flightHead->next;
        while (tempFlight != flightHead)
        {
            if (tempFlight->flights->id == flightid)
            {
                // 对应航班链表数目加一
                tempFlight->flights->tickets++;
            }
            tempFlight = tempFlight->next;
        }

        //重置用户票券后面的序号
        if (flag == 2)
        {
            while (temp_next != userNode->user->ticketHead)
            {
                temp_next->ticket->uid--;
                temp_next = temp_next->next;
            }
        }
        
    }
}

// 用户改签
void userChangeTicket(linklist_flight *flightHead, linklist_t *userNode)
{
    // 原理为用户选择需要改签的票，然后将自己所需改签的票退掉然后改成需要的那一张
    if (userNode->user->ticketHead->next == userNode->user->ticketHead)
    {
        printf("抱歉没有飞机票改签\n");
        return;
    }
    int flag = 0;
    int uid = 0;
    int id = 0;
    int flightid = 0;
    int i = 0;
    
    printf("-------------------------------------------用户改签-------------------------------------------\n");
    printf("-------------------------------------------航班列表-------------------------------------------\n");
    userFlightPrintf(flightHead);
    printf("\n");
    printf("-------------------------------------------本人票券-------------------------------------------\n");
    userPrintfTicket(userNode);
    printf("\n");
    while (1)
    {
        printf("输入需要改签的编号");
        scanf("%d", &uid);
        getchar();
        linklist_ticket *temp_id = userNode->user->ticketHead->next;
        while (temp_id != userNode->user->ticketHead)
        {
            if (uid == temp_id->ticket->uid)
            {
                i++;
            }
            temp_id = temp_id->next;
        }
        if (i == 0)
        {
            printf("不存在此编号\n");
            continue;
        }else{
            break;
        }
    }
    printf("是否改签(0|1)");
    scanf("%d", &flag);
    getchar();
    if (flag == 0)
    {
        return;
    }
    else
    {
        // 首先退票
        linklist_ticket *temp = userNode->user->ticketHead->next;
        linklist_ticket *temp_next = NULL;
        while (temp != userNode->user->ticketHead)
        {
            if (uid == temp->ticket->uid)
            {
                if (temp->next != userNode->user->ticketHead)
                {
                    temp_next = temp->next;
                    flag = 2;
                }
                // 航班编号赋值
                flightid = temp->ticket->id;
                // 删除链表节点
                temp->next->pre = temp->pre;
                temp->pre->next = temp->next;
                free(temp->ticket);
                temp->ticket = NULL;
                free(temp);
                temp = NULL;
                break;
            }

            temp = temp->next;
        }
        linklist_flight *tempFlight = flightHead->next;
        while (tempFlight != flightHead)
        {
            if (tempFlight->flights->id == flightid)
            {
                // 对应航班链表数目加一
                tempFlight->flights->tickets++;
            }
            tempFlight = tempFlight->next;
        }
        // 重置用户票券后面的序号
        if (flag == 2)
        {
            while (temp_next != userNode->user->ticketHead)
            {
                temp_next->ticket->uid--;
                temp_next = temp_next->next;
            }
        }
        // 然后重新购买飞机票
        printf("输入你所需要的航班编号:");
        scanf("%d", &id);
        purchaseTickets(id, userNode, flightHead);
    }
    printf("-----------------------------------------改签完成-----------------------------------------\n");
    system("clear");
}
