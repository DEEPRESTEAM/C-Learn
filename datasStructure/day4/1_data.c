#include"2_head.h"



/// @brief 头节点的初始化
/// @return 返回创建的头节点
linklist * creat_linklistHeadNode(){
    linklist * head = malloc(sizeof(linklist));
    if (head == NULL)
    {
        printf("空间申请失败\n");
        return NULL;
    }
    head->data = NULL;
    head->pre = head; 
    head->next = head;
    return head;
}


/// @brief 双向循环链表头插
/// @param head 头节点
/// @param newData 传入数据域
/// @param size 传入数据域大小
void insertLinklistToHead(linklist * head , void * newData , int size){
    if (head == NULL || newData == NULL || size < 0)
    {
        printf("参数错误\n");
        return;
    }
    linklist * newNode = malloc(sizeof(linklist));
    newNode->data = malloc(size);
    if (newNode == NULL || newNode->data == NULL)
    {
        printf("申请空间失败 \n");
        return;
    }
    //从 newData 复制 size 大小到 newNode->data 
    memcpy(newNode->data , newData , size);
    newNode->next = head->next;
    newNode->pre = head;
    head->next->pre = newNode;
    head->next = newNode;
}





/// @brief 双向循环链表的尾插
/// @param head 传入链表头节点
/// @param newData 传入数据域 
/// @param size 传入数据域大小
void insertlinklistToTail(linklist * head , void * newData , int size){
    if (head == NULL || newData == NULL || size <= 0)
    {
        printf("参数错误\n");
        return;
    }
    linklist * newNode = malloc(sizeof(linklist));
    newNode->data = malloc(size);
    linklist * temp = head->pre; 

    memcpy(newNode->data , newData , size);
    newNode->next = temp->next;
    newNode->pre = temp; 
    temp->next = newNode;
    head->pre = newNode;

}




//求出链表的节点个数
int findLinklistNodeCount(linklist * head){
    int count = 0;
    if (head == NULL || head->next == head)
    {
        printf("链表为空\n");
        return 0;
    }
    linklist * temp = head;
    while (temp->next != head)
    {
        count++;
        temp = temp->next;
    }
    return count;

}


//双向循环链表的打印
void showName(void * data){
    stu_t * stu = (stu_t *)data;
    printf("name = %s\n" , stu->name);
}
void showAge(void * data){
    stu_t * stu = (stu_t *)data;
    printf("age = %d\n" , stu->age);
}
void showAll(void * data){
    stu_t * stu = (stu_t *)data;
    printf("name = %s age =%d\n" , stu->name , stu->age);
}
void linklistPrintf(linklist * head , showkind show){
    if (head == NULL)
    {
        printf("链表违规\n");
        return;
    }
    if (head->next == head)
    {
        printf("链表为空\n");
        return;
    }
    linklist * temp = head->next;
    while (temp != head)
    {
        show(temp->data);
        temp = temp->next;
    }
    //printf("\n");
    // while (temp != head->next)
    // {
    //     printf("%d " , temp->data);
    //     temp = temp->pre;
    // }
    // printf("\n");
    
}
/// @brief 删除任意位置的节点
/// @param head //双向链表的头节点
/// @param index //需要删除的位置
void deleteLinklistNodeByIndex(linklist * head , int index){
    index = index % (findLinklistNodeCount(head) + 1);
    if (head == NULL || head->next == head)
    {
        printf("链表为空或链表不存在\n");
        return;
    }
    if (index == 0)
    {
        printf("不能删除头节点\n");
        return;
    }
    linklist * temp = head->next;
    int i = 1;
    while (i < index)
    {
        i++;
        temp = temp->next;
    }

    temp->next->pre = temp->pre;
    temp->pre->next = temp->next;
    free(temp->data);
    free(temp);
    
}

/// @brief 删除头节点
/// @param head 链表的头节点
/// @param data 需要传出的数据指针
/// @param size 空间大小
void deleteLinklistHeadNode(linklist * head , void * data , int size){
    if (head == NULL || head->next == head)
    {
        printf("链表为空或链表不存在\n");
        return;
    }
    linklist * temp = head->next;
    head->next = temp->next;
    temp->next->pre = head;

    memcpy(data , temp->data , size);
    free(temp->data);
    free(temp);
    return;
}

/// @brief 修改某个位置的数据内容
/// @param head 头节点
/// @param index 传入位置
/// @param data 需要修改的数据
/// @param size 修改数据的大小
void changeLinklistNodeContentByIndex(linklist * head , int index , void * data , int size){
    index = index % (findLinklistNodeCount(head) + 1);
    if (head == NULL || head->next == head || data == NULL || index <= 0 || size <= 0)
    {
        printf("参数错误或链表为空或链表不存在\n");
        return;
    }
    int i = 1;
    linklist * temp = head->next;
    while (i < index)
    {
        i++;
        temp = temp->next;
    }
    memcpy(temp->data , data , size);
    return;    
}

/// @brief 在任意位置插入
/// @param head 
/// @param index 
/// @param newDate 
/// @param size 
void insertLinklistNodeByIndex(linklist * head , int index , void * newDate , int size){
    index = index % (findLinklistNodeCount(head) + 1);
    if (head == NULL || newDate == NULL || size <= 0)
    {
        printf("链表不存在或参数错误\n");
        return;
    }
    int i = 1;
    linklist * temp = head->next;
    while (i < index)
    {
        i++;
        temp = temp->next;
    }
    linklist * newNode = malloc(sizeof(linklist));
    newNode->data = malloc(size);
    if (newNode == NULL || newDate == NULL)
    {
        printf("申请空间失败\n");
        return;
    }

    memcpy(newNode->data , newDate , size);
    //如果在头节点插入就变相在链表最后一个位置后面插入
    if (index == 0)
    {
        linklist * tail = head->pre;
        newNode->next = tail->next;
        newNode->pre = tail;
        tail->next = newNode;
        head->pre = newNode;
    }else{
        newNode->next = temp;
        newNode->pre = temp->pre;
        temp->pre->next = newNode;  
        temp->pre = newNode;
    }

}



int cmpName(void * data1 , void * data2){
    stu_t * stu1 = (stu_t *)data1;
    stu_t * stu2 = (stu_t *)data2;
    return strcmp(stu1->name , stu2->name);
}
int cmpAge(void * data1 , void * data2){
    stu_t * stu1 = (stu_t *)data1;
    stu_t * stu2 = (stu_t *)data2;
    return (stu1->age) - (stu2->age);
}
void findAllContentBySomeContent(linklist * head , cmpContent cmp , void * data){
    int count = 0;
    if (head == NULL || head->next == NULL || cmp == NULL || data == NULL )
    {
        printf("链表不存在或链表为空或参数错误\n");
        return;
    }
    linklist * temp = head->next;
    while (temp != head)
    {
       
        if (!cmp((temp->data) , data))
        {
            printf("name =%s age =%d\n" , ((stu_t *)(temp->data))->name , ((stu_t *)(temp->data))->age);
            count++;
        } 
        temp = temp->next;
    }
    if (count == 0)
    {
        printf("查询失败，查询内容不存在\n");
    }
    
}

/// @brief 删除双向循环链表的所有数据节点(利用头插法的原理)
/// @param head 传入头节点
void deleteAllLinklistNode(linklist **head){
    if ((*head)->next == *head)
    {
        free(*head);
        *head = NULL;
        return;
    }
    
    if ((*head) == NULL)
    {
        printf("链表不存在或链表数据节点为空\n");
        return;
    }
    //删除节点操作
    linklist * temp = (*head)->next;


    temp->next->pre = (*head);
    (*head)->next = temp->next;
    free(temp->data);
    free(temp);
    deleteAllLinklistNode(head);
}


/// @brief 删除尾节点
/// @param head 传入头节点
void deleteLinklistNodeToTail(linklist * head){
    if (head == NULL || head->next == head)
    {
        printf("链表不存在或链表为空 \n");
        return;
    }
    linklist * temp = head->pre;

    temp->pre->next = temp->next;
    temp->next->pre = temp->pre;
    
}

/// @brief 双向循环链表排序
/// @param head 传入链表头节点
void linklistSort(linklist * head){
    if (head == NULL || head->next == NULL)
    {
        printf("链表不存在或链表为空\n");
        return;
    }
    
    
}


#if 0
int main(int argc, char const *argv[])
{
    int arr[20] ={1,23,34,45,56,77,90,100,119};
    linklist * head = creat_linklistHeadNode();
    if (head == NULL)
    {
        printf("链表创建失败\n");\
        return -1;
    }
    stu_t stu[5] = {{"jack", 20}, {"marry", 21}, {"pitter", 22}, {"smith", 20}, {"join", 21}};
    for (int i = 0; i < 5; i++)
    {
        insertlinklistToTail(head, stu + i , sizeof(stu_t));
    }
    printf("---------------------头插法打印--------------------\n");
    linklistPrintf(head ,  showAll);



    printf("---------------------求出链表节点个数-----------------\n");
    int count = findLinklistNodeCount(head);
    printf("链表节点个数为:%d\n" , count);



    printf("---------------------在任意位删除除节点--------------------\n");
    printf("请输入删除的位置:\n");
    int index = 0;
    scanf("%d" , &index);
    getchar();
    deleteLinklistNodeByIndex(head , index);
    linklistPrintf(head , showAll);



    printf("---------------------删除头节点前------------------------\n");
    stu_t stu1 = {0};
    linklistPrintf(head , showAll);
    deleteLinklistHeadNode(head , &stu1 , sizeof(stu1));
    printf("---------------------删除头节点后------------------------\n");
    linklistPrintf(head , showAll);
    printf("删除的内容为： name =%s  age =%d\n" , stu1.name , stu1.age);



    printf("--------------------任意位置修改值-----------------------\n");
    printf("输入你要修改的位置:");
    scanf("%d" , &index);
    getchar();
    printf("输入你要修改的内容:");
    scanf("%s %d" , stu1.name , &stu1.age);
    getchar();
    changeLinklistNodeContentByIndex(head , index , &stu1 , sizeof(stu_t));
    linklistPrintf(head , showAll);



    printf("---------------------在任意位置插入信息-----------------------\n");
    printf("输入你要插入的位置:");
    scanf("%d" , &index);
    getchar();
    printf("输入你要插入的内容:");
    scanf("%s %d" , stu1.name , &stu1.age);
    getchar();
    insertLinklistNodeByIndex(head , index , &stu1 , sizeof(stu_t));
    linklistPrintf(head , showAll);



    printf("---------------------模糊查询---------------------\n");
    printf("输入你要查询的内容:");
    scanf("%s" , stu1.name);
    getchar();
    findAllContentBySomeContent(head , cmpAge , &stu1);

#if 0
    printf("---------------------删除所有数据节点---------------\n");
    linklistPrintf(head , showAll);
    deleteAllLinklistNode(head);
    printf("---------------------删除后---------------------\n");
    linklistPrintf(head,showAll);

#endif

    printf("---------------------删除尾节点---------------\n");
    linklistPrintf(head , showAll);
    deleteLinklistNodeToTail(head);
    printf("---------------------删除后---------------------\n");
    linklistPrintf(head , showAll);
    return 0;
}
#endif