#include<stdio.h>
//在c语言中     函数的定义  声明    和      调用

void prin_hello(void);  //声明      子程序


int main(int argc, char const *argv[])
{
    prin_hello();   //调用
    return 0;
}


//定义  实现
void prin_hello(){
    printf("hello\n");
}