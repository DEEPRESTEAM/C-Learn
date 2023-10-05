#include"railway.h"

//打印功能集成







/// @brief 打印存储在用户信息中的航班信息
/// @param head 传入链表的头节点
/// @param count 返回打印的次数
void userFlightPrintf(linklist_flight *flightHead)
{
    if (flightHead == NULL || flightHead->next == NULL)
    {
        printf("参数错误\n");
        return;
    }
    linklist_flight *temp = flightHead->next;
    while (temp != flightHead)
    {
        printf("序号：%d  起始地：%s  目的地：%s  起飞时间：%s  入口：%s  票量：%d  价格：%lf\n", temp->flights->id, temp->flights->originalPlace, temp->flights->destination, temp->flights->date, temp->flights->entrance, temp->flights->tickets, temp->flights->price);
        temp = temp->next;
    }
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
        printf("%ld %s\n", temp->user->accountNumber, temp->user->passwd);
        // printf("id = %d uid = %d accountNumber = %ld passwd = %s phone = %ld jurisdiction = %d idNumber = %lld name = %s \n" , temp->user->id , temp->user->uid , temp->user->accountNumber , temp->user->passwd , temp->user->phone , temp->user->jurisdiction , temp->user->idNumber , temp->user->name);
        temp = temp->next;
    }
}