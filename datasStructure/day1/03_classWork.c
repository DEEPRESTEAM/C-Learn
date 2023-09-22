#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct user
{
    //char * name;
    char name[20];
    int passwd;
}user_t;


typedef struct node
{
    user_t userm;
    struct node * next;
}node_t;


node_t * createLinkList(){
    //申请空间
    //填写节点域
    //填写节点中的指针部分
    node_t * head = (node_t *)malloc(sizeof(node_t));
    if (NULL == head)//NULL 写在左边比卸载右边好 
    {
        printf("mollec error\n");
        return NULL;
    }
    //填写节点中的数据
    head->userm.name;
    head->userm.passwd = 0;
    //填写节点中的指针部分
    head->next = NULL;
    return head;
}


//尾插法
int insertTailLinkList(node_t * head , char * name , int passwd){
    node_t * T = head;
    //参数判断
    if (head == NULL)
    {
        perror("this LinkList is illage\n");
        return -1;
    }
    //申请空间
    node_t * newNode = malloc(sizeof(node_t));
    if (newNode == NULL)
    {
        perror("newNode malloc error\n");
        return -1;
    }
    while (T->next != NULL)
    {  
        T = T->next; 
    }

    //填写节点中的数据
    //newNode->userm.name = name;
    strcpy(newNode->userm.name ,name);
    printf("你输入的数据是：%s\n" , head->userm.name);
    newNode->userm.passwd = passwd;
    //填写节点中的指针部分
    newNode->next = T->next;
    T->next = newNode;
    return 1;
}
// void addSum(node_t * head , char * name){
//     head->userm.name = name;
//     printf("-------------------------\n");
//     printf("%s\n" , head->userm.name);
//     printf("-------------------------\n");
// }
//递归打印
void recursivePrinting(node_t * T){
    
    if (T == NULL)
    {
        return;
    }
    printf("用户名：%s 密码：%d" , T->userm.name , T->userm.passwd);
    printf("\n");
    recursivePrinting(T = T->next);
} 

void print(node_t * head){
    node_t * T = head->next;
    if (head == NULL)
    {
        printf("链表为空\n");
    }
    recursivePrinting(T);
}





int main(int argc, char const *argv[])
{
    printf("----------注册账户----------\n");
    node_t * head = createLinkList();
    printf("%p\n" , head);
    char  name[10] = "0";
    int passwd = 0;
    for (int i = 0; i < 3; i++)
    {
        printf("请输入你的用户名与密码:\n");
        scanf("%s %d" , name , &passwd);
        getchar();
        insertTailLinkList(head , name ,passwd);
    }
    print(head);
    printf("%p\n" , head);
   
    
    
    return 0;
}
