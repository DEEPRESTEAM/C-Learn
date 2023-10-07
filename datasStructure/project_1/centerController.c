#include"railway.h"


//中央控制器



//链表创建，文件读取，用户航班读取
int prependants(linklist_flight * flightHead ,linklist_t * head , FILE * file , int size){
    system("clear");
    
    if (judgetHeadIsNull(head , flightHead))
    {
        printf("创建失败\n");
        return 0;
    }
    //从用户文件读取信息到链表中
    getgetFileToLinklist(head , file , size);
    //从航班文件读取信息到链表中
    FILE * file1 = file_open("flight.txt" , "r+");
    int count = getFlightFileToLinklist(flightHead , file1);
    return count;
}


//中央控制器，不同的用户功能选择
int centerController(linklist_flight * flightHead , linklist_t * head , user_t * user , int size )
{   
    int i = 0;
    linklist_t * user1 = NULL;
    int num = 0; 
    while (1)
    {
        showMenu();
        user1 = loginIntegration(head , user , size);
        sleep(1);
        system("clear");
        if (head->flag == 0)
        {
            return 0;
        }
        if (user1 == NULL)
        {
            continue;
        }
        num = ((user_t *)user1->user)->jurisdiction;
        switch (num)
        {
        case 1:
            if( adminController(head , flightHead) == 1){
                return 1;
            }
            break;
        case 0:
            userController(head , user1 , flightHead);
            break;
        default:
            printf("错误\n");
            break;
        }
    }
    
}