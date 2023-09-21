#include"file.h"


student stu[20];


int main(int argc, char const *argv[])
{
    int length = LENGTH;
    FILE * fp = file_open("1.txt" , "r+");
    readFileToStruct(stu , fp , length);
    int temp = login(stu , length);
    if (temp == 0 )
    {
        return 0;
    } 
    printf("登录成功\n");
    sleep(1);
    system("clear");
    menueFather(temp);
    functionSelection(stu , fp , temp , length);
    rewind(fp);
    inFile(stu , fp , length);
    return 0;
}