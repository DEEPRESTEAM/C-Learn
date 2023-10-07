#include"railway.h"




//管理员功能集成

int adminController(linklist_t * head , linklist_flight * flightHead){
    int i = 0;
    int numFun = 0;
    while (1)
    {
        adminControllerMenue();
        printf("输入功能序号\n");
        scanf("%d" , &numFun);
        getchar();
        switch (numFun)
        {
        case 1:
            printf("用户信息管理\n");
            userManageController(head );
            break;
        case 2:
            printf("航班信息管理\n");
            flightManageController(flightHead);
            break;
        case 3:
            return deletelib(head);
        case 4:
            printf("返回上一级\n");
            return 0;
        default:
            break;
        }
    }
    
}

//用户信息管理集成
void userManageController(linklist_t * head ){
    int id = 0;
    int flag = 0;
    if (head == NULL || head->next == head)
    {
        printf("链表不存在或链表为空\n");
        return;
    }
    

    while (1)
    {
        adminManageControllerMeaue();
        printf("输入功能编号\n");
        scanf("%d" , &flag);
        getchar();
        switch (flag)
        {
        case 1:
            printf("-------------------用户列表------------------\n");
            linkListPrintf(head);
            printf("修改用户\n");
            printf("输入你想修改的用户的id：");
            scanf("%d" , &id);
            linklist_t *temp_id = head->next;
            while (temp_id != head)
            {
                if (id == temp_id->user->id)
                {
                    break;
                }
                temp_id = temp_id->next;
            }
            if (temp_id == head)
            {
                printf("没有找到该序号用户\n");
                break;
            }
            changeUserMessage(head  , id);
            break;
        case 2:
            printf("-------------------用户列表------------------\n");
            linkListPrintf(head);
            deleteUserMessage(head);
            printf("-------------------删除完后用户信息--------------------\n");
            linkListPrintf(head);
            break;
        case 3:
            printf("返回上一级\n");
            return;
        default:
            break;
        }
    }
    
}




//修改用户信息
void adminChangeUserMessage(linklist_t * head){
    int num = 0;
    //首先查看所有用户信息
    linkListPrintf(head);
    //修改某一个用户的数据
    printf("输入所需要修改的编号：");
    scanf("%d",&num );
    getchar();

}

//通过选择修改用户信息
void changeUserMessage(linklist_t * head , int id){
    while (1)
    {   
        changeFunMenue();
        int flag = 0;
        printf("输入你想要修改的选项序号:");
        scanf("%d" , &flag);
        getchar();
        switch (flag)
        {
        case 1:
            printf("修改姓名\n");
            printf("输入修改后的姓名：");                                                                                                                                                                                                                                                                                                                                                  
            char name[20] = {0};
            scanf("%s" , name);
            getchar();
            changeFun(head, id, changeMesName , name);
            linkListPrintf(head);
            break;
        case 2:
            printf("修改电话\n");
            printf("输入修改后的电话：\n");
            long int phone = 0;
            scanf("%ld" , &phone);
            getchar();
            changeFun(head , id , changeMesPhone ,&phone);
            linkListPrintf(head);
            break;
        case 3:
            printf("修改权限\n");
            printf("输入修改后的权限(0|1)");
            int judge = 0;
            scanf("%d" , &judge);
            getchar();
            changeFun(head , id , changeMesJudege , &judge);
            linkListPrintf(head);
            break;
        case 4:
            printf("修改密码\n");
            printf("输入修改后的密码:");
            char passwd[20] = {0};
            scanf("%s" , passwd);
            getchar();
            changeFun(head , id , changeMesPasswad , passwd);
            linkListPrintf(head);
            break;
        case 5:
            printf("修改用户身份证号码\n");
            printf("输入修改后的身份证号码:");
            long long int idNum = 0;
            scanf("%lld" , &idNum);
            getchar();
            changeFun(head , id , changeMesIdNumber , &idNum);
            linkListPrintf(head);
            break;
        case 6:
            printf("返回上一级\n");
            return;
        default:
            break;
        }
    }
    
}




//修改密码
linklist_t * changeMesPasswad(linklist_t * node , void * data){
    strcpy(node->user->passwd , (char *)data);
    return node;
}
//修改电话
linklist_t *changeMesPhone(linklist_t *node, void *data)
{
    node->user->phone = *(long int*)data;
    node->user->accountNumber = *(long int *)data;
    return node;
}
// 修改权限
linklist_t *changeMesJudege(linklist_t *node, void *data)
{
    node->user->jurisdiction = *(int *)data;
    return node;
}
//修改身份证号码
linklist_t *changeMesIdNumber(linklist_t *node, void *data)
{
    node->user->idNumber = *(long long int *)data;
    return node;
}
// 修改姓名
linklist_t *changeMesName(linklist_t *node, void *data)
{
    strcpy(node->user->name, (char *)data);
    return node;
}

void changeFun(linklist_t * head , int num , changeMes changeMesFun , void * data){
    if (head == NULL || head->next == head)
    {
        printf("参数为空或没有数据用户\n");
        return;
    }
    linklist_t * temp = head->next;
    while (temp != head)
    {
        if (temp->user->id == num)
        {
            //修改函数的值
            temp = changeMesFun(temp , data);
            break;
        }
        temp = temp->next;
    }
    if (temp == head)
    {
        printf("没有找到修改的值\n");
    }
    
}


//删除用户
void deleteUserMessage(linklist_t * head){
    if (head == NULL || head->next == head)
    {
        printf("链表为空或无数据节点\n");
        return;
    }
    printf("输入你想要删除用户的id:");
    int id = 0;
    scanf("%d" , &id);
    getchar();
    linklist_t * temp_id = head->next;
    while (temp_id != head)
    {
        if (id == temp_id->user->id && temp_id->user->jurisdiction != 1)
        {
            break;
        }
        temp_id = temp_id->next;
    }
    if (temp_id == head)
    {
        printf("没有找到该序号用户||不能删除管理员账户\n");
        return;
    }
    int flag = 0;
    while (1)
    {
        printf("是否执行删除操作 (1|0)\n");
        scanf("%d" , &flag);
        getchar();
        linklist_t * temp_after = NULL;
        if (flag == 0)
        {
            return;
        }else if(flag == 1){
            linklist_t *temp = head->next;
            while (temp != head)
            {
                if (id == temp->user->id)
                {
                    if (temp->next != head)
                    {
                        temp_after = temp->next;
                        flag = 2;
                    }
                    //执行删除操作
                    temp->next->pre = temp->pre;
                    temp->pre->next = temp->next;
                    //逐级释放空间
                    free(temp->user->ticketHead->ticket);
                    temp->user->ticketHead->ticket = NULL;
                    free(temp->user->ticketHead);
                    temp->user->ticketHead = NULL;
                    free(temp->user);
                    temp->user = NULL;
                    free(temp);
                    temp = NULL;
                    break;
                }
                temp = temp->next;
            }
            if (flag == 2)
            {
                while (temp_after != head)
                {
                    temp_after->user->id--;
                    temp_after = temp_after->next;
                }
            }
            return;
            
        }else{
            printf("输入错误请重新输入\n");
            continue;
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
    free(temp->user->ticketHead->ticket);
    temp->user->ticketHead->ticket = NULL;
    free(temp->user->ticketHead);
    temp->user->ticketHead = NULL;
    free(temp->user);
    temp->user = NULL;
    free(temp);
    temp = NULL;
    deletelib(head);
}

// 航班信息管理集成
void flightManageController(linklist_flight * head )
{
    int id = 0;
    int index = 0;
    while (1)
    {
        adminFlightControllerMeaue();
        printf("输入功能序号\n");
        int funNum = 0;
        scanf("%d", &funNum);
        getchar();
        switch (funNum)
        {
        case 1:
            printf("----------------------------------------航班信息-----------------------------------------\n");
            userFlightPrintf(head);
            printf("修改航班信息\n");
            printf("输入你想修改的航班的id：");
            scanf("%d", &id);
            linklist_flight *temp_id = head->next;
            while (temp_id != head)
            {
                if (id == temp_id->flights->id)
                {
                    break;
                }
                temp_id = temp_id->next;
            }
            if (temp_id == head)
            {
                printf("没有找到该序号用户\n");
                break;
            }
            changeFlightMessage(head , id);
            printf("-----------------------------------------修改后的航班列表--------------------------------------------\n");
            userFlightPrintf(head);
            break;
        case 2:
            printf("----------------------------------------------航班信息----------------------------------------------\n");
            userFlightPrintf(head);
            deleteFlightMes(head);
            printf("----------------------------------------------删除后航班信息----------------------------------------------\n");
            break;
        case 3:
            // 航班增加
            printf("-----------------------------------------添加前的航班列表--------------------------------------------\n");
            userFlightPrintf(head);
            printf("\n");
            printf("输入你添加的位置：");
            scanf("%d" , &index);
            addFlightMes(head, index);
            printf("-----------------------------------------添加后的航班列表--------------------------------------------\n");
            userFlightPrintf(head);
            break;
        case 4:
            system("clear");
            return;
        default:
            break;
        }
    }
}

// 修改航班信息集成
void changeFlightMessage(linklist_flight * head, int id)
{
    while (1)
    {
        changeFlightFunMenue();
        int flag = 0;
        printf("输入你想要修改的选项序号:");
        scanf("%d", &flag);
        getchar();
        switch (flag)
        {
        case 1:
            printf("修改目的地\n");
            printf("输入修改后的目的地：");
            char destination[20] = {0};
            scanf("%s", destination);
            getchar();
            changeFlightFun(head, id, changeFlightDestination, destination);
            userFlightPrintf(head);

            break;
        case 2:
            printf("修改价格\n");
            printf("输入修改后的价格：\n");
            double price = 0;
            scanf("%lf", &price);
            getchar();
            changeFlightFun(head, id, changeFlightPrice, &price);
            userFlightPrintf(head);

            break;
        case 3:
            printf("修改票量\n");
            printf("输入修改后的票量");
            int ticketNums = 0;
            scanf("%d", &ticketNums);
            getchar();
            changeFlightFun(head, id, changeFlightTicket, &ticketNums);
            userFlightPrintf(head);

            break;
        case 4:
            printf("修改出发时间\n");
            printf("输入修改后的出发时间:");
            char date[20] = {0};
            scanf("%s", date);
            getchar();
            changeFlightFun(head, id, changeFlightDate, date);
            userFlightPrintf(head);
            break;
        case 5:
            printf("返回上一级\n");
            return;
        default:
            break;
        }
    }
}

//修改票券数量
linklist_flight * changeFlightTicket(linklist_flight * node , void * data )
{
    node->flights->tickets = *(int *)data;
    return node;
}

//修改票券价格
linklist_flight *changeFlightPrice(linklist_flight *node, void *data)
{
    node->flights->price = *(double *)data;
    return node;
}
//修改票券出发时间
linklist_flight *changeFlightDate(linklist_flight *node, void *data)
{
    strcpy(node->flights->date , (char *)data);
    return node;
}
//修改票券目的地
linklist_flight *changeFlightDestination(linklist_flight *node, void *data)
{
    strcpy(node->flights->destination , (char *)data);
    return node;
}

void changeFlightFun(linklist_flight *head, int num, changeFlightMes changeFlight, void *data)
{
    if (head == NULL || head->next == head)
    {
        printf("参数为空或没有数据用户\n");
        return;
    }
    linklist_flight *temp = head->next;
    while (temp != head)
    {
        if (temp->flights->id == num)
        {
            // 修改函数的值
            temp = changeFlight(temp, data);
            break;
        }
        temp = temp->next;
    }
    if (temp == head)
    {
        printf("没有找到修改的值\n");
    }
}


//删除航班信息


void deleteFlightMes(linklist_flight * head){
    if (head == NULL || head->next == head)
    {
        printf("链表不存在或链表为空\n");
        return;
    }
    //先审查id是否存在
    printf("输入你想要删除的id号：");
    int id = 0;
    scanf("%d" , &id);
    getchar();
    linklist_flight * temp_id = head->next;
    while (temp_id != head)
    {
        if (temp_id->flights->id == id)
        {
            break;
        }
        temp_id = temp_id->next;
        
    }
    if (temp_id == head)
    {
        printf("此序号不存在\n");
        return;
    }
    linklist_flight * temp = head->next;
    int flag = 0;
    while (1)
    {
        printf("是否执行删除操作 (1|0)\n");
        scanf("%d", &flag);
        getchar();
        linklist_flight *temp_after = NULL;
        if (flag == 0)
        {
            return;
        }
        else if (flag == 1)
        {
            linklist_flight *temp = head->next;
            while (temp != head)
            {
                if (id == temp->flights->id)
                {
                    // 找到该节点的下一个节点且下个节点不能为头节点
                    if (temp->next != head)
                    {
                        temp_after = temp->next;
                        flag = 2;
                    }
                    // 执行删除操作
                    temp->next->pre = temp->pre;
                    temp->pre->next = temp->next;
                    // 逐级释放空间
                    free(temp->flights);
                    temp->flights = NULL;
                    free(temp);
                    temp = NULL;
                    break;
                }
                temp = temp->next;
            }
            if(flag == 2){
                while (temp_after != head)
                {
                    temp_after->flights->id--;
                    temp_after = temp_after->next;
                }
            }
            return;
        }
        else
        {
            printf("输入错误请重新输入\n");
            continue;
        }
    }
}


//航班增加
void addFlightMes(linklist_flight * head , int index){
    printf("---------------------------------添加航班---------------------------------\n");
    index = index % (FlightLinklistNodeCounts(head) + 1);
    if (head == NULL || index <= 0)
    {
        printf("参数错误\n");
        return;
    }
    linklist_flight * temp = head->next;
    int i = 1;
    while (i < index)
    {
        i++;
        temp = temp->next;
    }
    //插入航班，分配空间
    linklist_flight * newNode = malloc(sizeof(linklist_flight));
    newNode->flights = malloc(sizeof(flight_t));
    if (newNode == NULL || newNode->flights == NULL)
    {
        printf("申请空间失败\n");
        return;
    }
    //输入航班信息
    flight_t flight = {0};
    flight.id = index;
    printf("输入始发地:");
    scanf("%s" , flight.originalPlace);
    getchar();
    printf("输入目的地:");
    scanf("%s" , flight.destination);
    getchar();
    printf("输入出发时间:");
    scanf("%s" , flight.date);
    getchar();
    printf("输入航班入口\n");
    scanf("%s" , flight.entrance);
    getchar();
    printf("输入票量:");
    scanf("%d" , &flight.tickets);
    getchar();
    printf("输入票价:");
    scanf("%lf" , &flight.price);
    getchar();
    //信息复制
    memcpy(newNode->flights , &flight , sizeof(flight_t));


    //节点连接
    newNode->next = temp;
    newNode->pre = temp->pre;
    temp->pre->next = newNode;
    temp->pre = newNode;

    //将后面的序号改变

    linklist_flight * Node = newNode->next;
    while (Node->next != head)
    {
        Node->flights->id++;
        Node = Node->next;
    }
    
}



