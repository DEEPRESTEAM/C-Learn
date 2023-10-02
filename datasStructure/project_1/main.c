#include"railway.h"

/**
 * 航班管理系统
*/
int main(int argc, char const *argv[])
{
    linklist_t *head = creatHeadNode();
    FILE *fp = file_open("user.txt", "r+");
    //前置初始化
    int count = prependants(head , fp , sizeof(user_t));
    user_t user = {0};
    int i = centerController(head , &user , sizeof(user_t), count);
    if (i == 1)
    {
        free(head->user);
        head->user = NULL;
        free(head);
        head = NULL;
        return 0;
    }
    
    linkListPrintf(head);
    userFlightPrintf(head , 15);
    
}
