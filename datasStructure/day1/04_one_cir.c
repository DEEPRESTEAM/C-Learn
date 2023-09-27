#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct stu
{
    char name[21];
    int age;
} stu_t;

typedef struct node
{
    stu_t *student;
    struct node *next;
} linklist;

/// @brief 创建链表(头节点)
/// @return //返回创建链表后的头节点
linklist *creatHeadNode()
{
    linklist *head = malloc(sizeof(linklist));
    if (head == NULL)
    {
        return NULL;
    }
    head->student = NULL;
    head->next = head;
    return head;
}

/// @brief 循环链表头插法
/// @param head 头节点
/// @param stu 数据域结构体指针
void insertLinklistToHead(linklist *head, stu_t *stu)
{
    if (head == NULL || stu == NULL)
    {
        printf("error\n");
        return;
    }
    // 申请节点空间
    linklist *newNode = malloc(sizeof(linklist));
    newNode->student = malloc(sizeof(stu_t));
    if (newNode == NULL || newNode->student == NULL)
    {
        printf("申请空间失败\n");
    }
    // 填写数据加链接
    *newNode->student = *stu;
    // 修改指针
    newNode->next = head->next;
    head->next = newNode;
    return;
}

/// @brief 尾插法
/// @param head 头节点
/// @param stu 数据域结构体指针
void insertLinklistToTail(linklist *head, stu_t *stu)
{
    if (head == NULL)
    {
        printf("链表为空\n");
        return;
    }
    linklist *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    linklist *newNode = malloc(sizeof(linklist));
    newNode->student = malloc(sizeof(stu_t));
    if (newNode == NULL || newNode->student == NULL)
    {
        printf("申请空间失败\n");
        return;
    }
    *newNode->student = *stu;
    newNode->next = temp->next;
    temp->next = newNode;
}

/// @brief 计算单向循环链表的节点个数
/// @param head 整条链表的头节点
/// @return 返回节点个数
int findLinklistNodeCount(linklist *head)
{
    int count = 0;
    if (head == NULL || head->next == head)
    {
        printf("链表为空或链表不存在\n");
        return -1;
    }
    linklist *temp = head->next;
    while (temp != head)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

/// @brief 查找任意位置的节点并将其内容进行输出
/// @param head 链表的头节点
/// @param index 位置
void findLinklistContextByIndex(linklist *head, int index)
{
    int i = 1;
    if (head == NULL || head->next == head)
    {
        printf("链表不存在或链表为空\n");
        return;
    }
    linklist *temp = head->next;
    int nodeSite = index % (findLinklistNodeCount(head) + 1);
    while (i < nodeSite)
    {
        i++;
        temp = temp->next;
    }
    printf("name = %s age = %d\n", temp->student->name, temp->student->age);
    return;
}


/// @brief 在任意位置插入数据
/// @param head 链表头
/// @param stu 需要插入的数据
/// @param index 需要插入在哪个位置
void insertNodeByIndex(linklist * head , stu_t * stu ,int index){
    int i = 0;
    if (head == NULL || head->next == head || index <= 0)
    {
        printf("参数错误\n");
        return;
    }
    linklist * temp = head;
    while (i < index -1)
    {
        i++;
        temp = temp->next;
    }
    //申请空间
    linklist * newNode = malloc(sizeof(linklist));
    newNode->student = malloc(sizeof(stu_t));
    if (newNode == NULL || newNode->student == NULL)
    {
        printf("申请空间失败\n");
        return;
    }
    strcpy(newNode->student->name , stu->name);
    newNode->student->age = stu->age;
    newNode->next = temp->next;
    temp->next = newNode;
    
    
}



/// @brief 删除单向循环链表的任意节点 
/// @param head 单向循环链表的头节点
/// @param index 需要删除的位置
void deleteNodeByIndex(linklist * head , int index ){
    int i  = 1;
    index = index % (findLinklistNodeCount(head) + 1);
    if (index == 0)
    {
        printf("头节点无法删除\n");
        return;
    }
    if (head == NULL || head->next == head )
    {
        printf("链表为空\n");
    }
    linklist * temp = head , *after = NULL;
    while (i < index )
    {
        i++;
        temp = temp->next;
    }
    after = temp->next;
    temp->next = temp->next->next;
    free(after);
}



/// @brief 删除链表的第一个数据节点
/// @param head //链表的头节点
void deleteLinklistFirsyNode( linklist * head ){
    if (head == NULL || head->next == head)
    {
        printf("链表为空或者链表无数据\n");
        return;
    }
    linklist * temp = head->next;
    head->next = temp->next;
    free(temp);
    return;
}




/// @brief 删除链表数据节点的最后节点
/// @param head 链表的头节点
void deleteLinklistLastNode(linklist * head){
    if (head == NULL || head->next == head)
    {
        printf("链表为空，或链表无节点\n");
        return;
    }
    linklist * temp = head->next , *after = NULL;
    while (temp->next->next != head)
    {
        temp = temp->next;
    }
    after = temp->next;
    temp->next = after->next;
    free(after);
    
}


/// @brief 递归删除链表的所有数据结点
/// @param head 链表的头节点
void deleteAllLinklist(linklist * head){
    if (head == NULL || head->next == head)
    {
        printf("链表为空，或链表无节点\n");
        return;
    }
    linklist * temp = head->next;
    head->next = temp->next;
    free(temp);
    deleteAllLinklist(head);
}












typedef int(cmpcontext)(stu_t *stu1, stu_t *stu2);
int cmpName(stu_t *stu1, stu_t *stu2)
{
    return strcmp(stu1->name, stu2->name);
}

int cmpAge(stu_t *stu1, stu_t *stu2)
{
    return stu1->age - stu2->age;
}
/// @brief 根据部分内容查找所有的内容
/// @param head 链表头节点
/// @param cmp 内容对比函数
/// @param stu 传输过来的数据
/// @return 返回找到的节点
linklist *findAllContentByPartialContent(linklist *head, cmpcontext *cmp, stu_t *stu)
{
    if (head == NULL || head->next == NULL)
    {
        printf("链表不存在或链表为空\n");
        return NULL;
    }
    linklist *temp = head->next;
    while (temp != head)
    {
        if (!cmp(temp->student, stu))
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}



// void deleteNode(linklist * head){
//     if (head == NULL)
//     {
//         printf("error\n");
//         return;
//     }


//     linklist * temp = head->next;
//     free(temp);
//     printf("%s %d\n" , temp->student->name , temp->student->age);
// }












typedef void(showkind)(stu_t *stu);

void showName(stu_t *stu)
{
    printf("name = %s \n", stu->name);
}
void showAge(stu_t *stu)
{
    printf("age = %d \n", stu->age);
}
void showAll(stu_t *stu)
{
    printf("name = %s age = %d\n", stu->name, stu->age);
}

/// @brief 打印单向循环链表
void linklistPrintf(linklist *head, showkind *showkind)
{
    if (head == NULL || head->next == NULL)
    {
        printf("此链表不存\n");
        return;
    }
    linklist *temp = head->next;
    while (temp != head)
    {
        showkind(temp->student);
        temp = temp->next;
    }
}









int main(int argc, char const *argv[])
{
    linklist *head = creatHeadNode();
    if (head == NULL)
    {
        printf("分配空间失败\n");
        return -1;
    }
    printf("%p %p %p\n", head, head->student, head->next);

    stu_t stu[5] = {{"jack", 20}, {"marry", 21}, {"pitter", 22}, {"smith", 20}, {"join", 21}};
    for (int i = 0; i < 5; i++)
    {
        insertLinklistToTail(head, stu + i);
    }
    printf("--------------只打印年龄--------------\n");
    linklistPrintf(head, showAge);
    printf("--------------只打印名字--------------\n");
    linklistPrintf(head, showName);
    printf("--------------全部打印--------------\n");
    linklistPrintf(head, showAll);
    printf("--------------链表结点个数--------------\n");
    int count = findLinklistNodeCount(head);
    printf("count = %d\n", count);
    printf("--------------输出第Index位置的信息--------------\n");
    int index = 0;
    printf("输入你要查找的位置：");
    scanf("%d", &index);
    getchar();
    findLinklistContextByIndex(head, index);
    printf("-------------------模糊查找-----------------\n");
    printf("请输入你想查找的姓名:");
    stu_t stu1 = {0};
    scanf("%s", stu1.name);
    getchar();
    linklist *temp = findAllContentByPartialContent(head, cmpName, &stu1);
    if (temp == NULL)
    {
        printf("没查到此内容\n");
    }
    else
    {
        printf("%s %d\n", temp->student->name, temp->student->age);
    }
    printf("------------------在任意位置插入数据---------------\n");
    printf("请输入你要在哪个位置插入数据 :");
    scanf("%d" , &index);
    getchar();
    printf("输入你要插入的数据:");
    scanf("%s  %d" , stu1.name , &stu1.age);
    insertNodeByIndex(head , &stu1 , index);
    linklistPrintf(head ,showAll);



    printf("-----------------在任意位置删除节点------------------\n");
    printf("请输入你想要删除节点的位置:");
    scanf("%d" , &index);
    getchar();



    printf("--------------------删除前的链表----------------\n");
    linklistPrintf(head , showAll);
    deleteNodeByIndex(head , index);



    printf("--------------------删除前的链表----------------\n");
    linklistPrintf(head , showAll);



    printf("------------------删除链表的头节点----------------\n");
    linklistPrintf(head , showAll);
    deleteLinklistFirsyNode(head);
    printf("----------------------------------------------------\n");
    linklistPrintf(head , showAll);



    printf("------------------删除链表的尾节点-----------------\n");
    linklistPrintf(head , showAll);
    deleteLinklistLastNode(head);
    printf("----------3------------------------------------------\n");
    linklistPrintf(head , showAll);



    printf("-------------------删除整条链表----------------------\n");
    deleteAllLinklist(head);
    if (head->next == head)
    {
        printf("链表删除成功\n");
    }
    
    printf("%p %p %p\n" , head , head->next , head->student);

    //deleteNode(head);
    return 0;
}
