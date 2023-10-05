#include"railway.h"

/**
 * 航班管理系统
*/
int main(int argc, char const *argv[])
{
    linklist_t *head = creatHeadNode();
    linklist_flight * flghtHead = creatHeadFlightNode(); 
    FILE *fp = file_open("user.txt", "r+");
    //前置初始化
    int count = prependants(flghtHead , head , fp , sizeof(user_t));
    user_t user = {0};
    int i = centerController(flghtHead , head , &user , sizeof(user_t), count);
    linkListPrintf(head);
    userFlightPrintf(flghtHead);
    if (i == 1)
    {
        free(head->user);
        head->user = NULL;
        free(head);
        head = NULL;
        return 0;
    }
    
    
    
}
