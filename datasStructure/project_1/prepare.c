#include "railway.h"


//链表创建，插入，文件读取集成





// 主双向链表的头节点的创建
linklist_t * creatHeadNode()
{
    linklist_t *head = malloc(sizeof(linklist_t));
    head->user = malloc(sizeof(user_t));
    if (head == NULL || head->user == NULL )
    {
        printf("申请空间失败\n");
        return NULL;
    }
    head->user->id = 0;
    head->user->uid = 100000;
    head->flag = 1;
    head->pre = head->next = head;
    return head;
}

//航班存储双向循环链表的创建
linklist_flight * creatHeadFlightNode(){
    linklist_flight * flightHead = malloc(sizeof(linklist_flight));
    flightHead->flights = malloc(sizeof(flight_t));
    if (flightHead == NULL)
    {
        printf("航班存储双向循环链表申请空间失败\n");
        return NULL;
    }
    flightHead->flights = NULL;
    flightHead->next = flightHead->pre = flightHead;
    return flightHead;    
}
//用户票券双向循环链表的创建
void  creatHeadTicketNode(user_t * user){
    linklist_ticket * ticketHead = malloc(sizeof(linklist_ticket));
    if (ticketHead == NULL)
    {
        printf("用户票券双向循环链表申请空间失败\n");
    }
    ticketHead->ticket = NULL;
    ticketHead->next = ticketHead->pre = ticketHead;
    user->ticketHead = ticketHead;
}

/// @brief 判断头节点是否创建成功
/// @param head  传入刚创建的头节点
/// @return 创建失败返回 -1 成功返回 0；
int judgetHeadIsNull(linklist_t *head , linklist_flight * flightHead)
{
    if (head == NULL && flightHead == NULL)
    {
        return -1;
    }
    else
    {
        return 0;
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
        creatHeadTicketNode(newNode->user);
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


/// @brief 读取航班文件读取到航班双向链表中
/// @param flightHead 航班双向链表头节点
/// @param file 输入读取的文件指针
/// @return 返回头节点
int getFlightFileToLinklist(linklist_flight * flightHead, FILE *file)
{
    if (flightHead == NULL || file == NULL)
    {
        printf("链表为空无法读取或文件打开失败\n");
        return -1;
    }
    // 文件读取内容默认使用尾插法读取
    int flag = 1;
    int count = 0;
    linklist_flight * temp = flightHead;
    while (flag)
    {
        linklist_flight *newNode = malloc(sizeof(linklist_flight));
        newNode->flights = malloc(sizeof(flight_t));
        flag = fscanf(file, "%d %s %s %s %s %d %lf", &newNode->flights->id, newNode->flights->originalPlace, newNode->flights->destination, newNode->flights->date, newNode->flights->entrance, &newNode->flights->tickets, &newNode->flights->price);
        if (flag == EOF)
        {
            free(newNode->flights);
            newNode->flights = NULL;
            free(newNode);
            break;
        }
        count++;
        if (newNode == NULL || newNode->flights == NULL)
        {
            printf("新节点空间分配失败\n");
            return -1;
        }
        while (temp->next != flightHead)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->pre = temp;
        temp->next = newNode;
        flightHead->pre = newNode;
    }
    return count;
}


//从结构体读取到文件中去

//读取用户文件
void readUserStructMesToFile(FILE * fp , linklist_t * head){
    if (fp == NULL || head == NULL || head->next == head)
    {
        printf("参数错误\n");
        return;
    }
    linklist_t * temp = head->next;
    fopen("user.txt" , "w+");
    while (temp != head)
    {
        //读取文件操作
        //首先将文件清空
        fprintf(fp, "%d %d %ld %s %ld %d %lld %s\n", temp->user->id, temp->user->uid, temp->user->accountNumber, temp->user->passwd, temp->user->phone, temp->user->jurisdiction, temp->user->idNumber, temp->user->name);
        //再以R+打开文件
        temp = temp->next;
    }
    if (temp == head)
    {
        printf("读取完成\n");
    }
    
}

//读取航班链表到文件中
void readFlightStructToFile(linklist_flight * head , FILE * fp){
    if (head == NULL || head->next == head || fp == NULL)
    {
        printf("参数错误\n");
        return;
    }
    linklist_flight * temp = head->next;
    fopen("flight.txt", "w+");
    while (temp != head)
    {
        fprintf(fp, "%d %s %s %s %s %d %lf\n", temp->flights->id, temp->flights->originalPlace, temp->flights->destination, temp->flights->date, temp->flights->entrance, temp->flights->tickets, temp->flights->price);
        temp = temp->next;
    }
    if (temp == head)
    {
        printf("航班读取完毕\n");
    }
    
    
}

