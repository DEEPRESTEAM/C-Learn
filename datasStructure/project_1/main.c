#include"railway.h"

/**
 * 航班管理系统
*/
int main(int argc, char const *argv[])
{
    linklist_t *head = creatHeadNode();
    linklist_flight * flghtHead = creatHeadFlightNode(); 
    FILE *fp = file_open("user.txt", "r+");
    FILE * flight = file_open("flight.txt" , "r+");
    //前置初始化
    prependants(flghtHead , head , fp , sizeof(user_t));
    user_t user = {0};
    int i = centerController(flghtHead , head , &user , sizeof(user_t));
    //linkListPrintf(head);
    //userFlightPrintf(flghtHead);
    if (i == 1)
    {   
        //管理员删库跑路释放所有空间
        deleteMainLinklist(&head);
        deleteFilght(&flghtHead);
        remove("user.txt");
        remove("flight.txt");
        return -1;
    }
   
    //将该表的值全部填入到文件中
    rewind(fp);
    readUserStructMesToFile(fp , head);
    readFlightStructToFile(flghtHead ,flight );
    fclose(fp);
    fclose(flight);
    //程序结束释放所有申请的空间
    deletelib(head);
    deleteMainLinklist(&head);
    deleteFilght(&flghtHead);
    return 0;
}
