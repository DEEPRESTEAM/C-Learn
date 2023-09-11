#include<stdio.h>
#include<string.h>
int main(){
	//实现先输入一个字符串，然后将其逆序输出
	char str[100]={"\0"};
	scanf("%s",&str);
	int length = strlen(str);
	for(int i = length-1 ; i >= 0 ; i--){
		printf("%c",str[i]);
	}
	return 0;
}
