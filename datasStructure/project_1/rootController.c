#include"railway.h"


int adminController(linklist_t * head){
    int i = 0;
    int numFun = 0;
    while (1)
    {
        printf("输入功能序号\n");
        scanf("%d" , &numFun);
        getchar();
        switch (numFun)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            return deletelib(head);
            break;
        default:
            break;
        }
    }
    
}


//删除双向循环链表中的所有节点
int deletelib(linklist_t * head){
    if (head->next == head)
    {
        return 1;
    }
    //移除头节点的下一个节点
    linklist_t * temp = head->next;
    //将当前节点断开
    temp->pre->next = temp->next;
    temp->next->pre = temp->pre;
    //释放空间
    free(temp->user);
    temp->user = NULL;
    free(temp);
    temp = NULL;
    deletelib(head);
}
