#include"railway.h"

//链表操作集成



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

// 将航班双向循环链表删除
void deleteFilght(linklist_flight **head)
{
    if ((*head)->next = *head)
    {
        free(*head);
        *head = NULL;
        return;
    }
    linklist_flight *temp = (*head)->next;
    // 释放空间
    free(temp->flights);
    temp->flights = NULL;
    free(temp);
    deleteFilght(head);
}

// 主链表删除头节点
void deleteMainLinklist(linklist_t **head)
{
    free((*head)->user->ticketHead);
    (*head)->user->ticketHead = NULL;
    free((*head)->user);
    (*head)->user = NULL;
    free(*head);
    *head = NULL;
    return;
}

// 将用户票券双向循环链表删除
void deleteTicketLinklist(linklist_ticket **ticketHead)
{
    if ((*ticketHead)->next == *ticketHead)
    {
        free((*ticketHead)->ticket);
        (*ticketHead)->ticket = NULL;
        free(*ticketHead);
        *ticketHead = NULL;
        return;
    }
    linklist_ticket *temp = (*ticketHead)->next;
    free(temp->ticket);
    temp->ticket = NULL;
    free(temp);
    temp = NULL;
    deleteTicketLinklist(ticketHead);
}

// 求出航班链表节点个数
int FlightLinklistNodeCounts(linklist_flight *head)
{
    int count = 0;
    if (head == NULL)
    {
        printf("链表不存在\n");
        return -1;
    }
    linklist_flight *temp = head;
    while (temp->next != head)
    {
        count++;
        temp = temp->next;
    }
    return count;
}