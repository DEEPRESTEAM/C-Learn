#include<stdio.h>
#include <stdlib.h>


//函数指针作为指针函数的返回值
typedef int(*FUNC)(int a, int b);      //定义一个FUNC代表 int(*)(int, int) 类型
 
//即上面需要返回的BFunction函数，执行加法操作
int BFuction(int a, int b)
{
	return a + b;
}
 
FUNC AFunction(const char * ch, int(*p)(int , int )) //这实际上就是 “类型名称 对象名称”，看起来就比较自然了
{
	if (ch == "add")  //只有传入“add”的时候才返回加法函数，否则返回null
	{
		return p;
	}
	else
	{
		return NULL;
	}
}
 
 
int main()
{
	//返回的类型要与定义的BFunction兼容,也是“类型名称 对象名称”的表示
	FUNC p = AFunction("add", BFuction);
	int result = p(1000, 2000);
	printf("the result is : %d\n", result);
 
	//getchar();
	return 0;
}