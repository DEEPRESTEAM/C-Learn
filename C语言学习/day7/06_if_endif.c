#include<stdio.h>
//if defined(WIN32)
//Windows   平台的代码
//#elif defined(LINUX)
//LINUX平台代码
//#else
//其他平台的代码
//#endif


#define M
//在写单片机时，由于单片机内部资源有限，有些不需要的功能或函数 我们可以屏蔽
#define SUM

#ifdef SUM
void hello(){
    static int i = 1;
    printf("%d\n" , i++);
    return;
}
#endif

int main(int argc, char const *argv[])
{
    #ifdef SUM
        hello();
        hello();
        hello();
        hello();
        hello();
        hello();
        hello();
        hello();
        hello();
        hello();
        hello();
        hello();
        hello();
        hello();
        hello();
        hello();
        hello();
    #endif 
    return 0;
}
