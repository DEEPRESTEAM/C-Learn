#include<stdio.h>
int main(int argc, char *argv[]){
	char arr1[3]={'a','b','c'};
	char arr2[6]={'d','e','f'};
	//int length = sizeof(arr1) / sizeof(char);
	
	printf("arr1:%s %p\n",arr1,&arr1[2]);
	printf("arr2:%s %p\n",arr2,&arr2[0]);
	int a[]={1,2,3};
	int b[6]={1,2,3};
	printf("a: %p\n",&a[2]);
	printf("b: %p\n",b);



#if 0
	for(int i = 0 ; i < length ;i++){
		putchar(arr1[i]);
	}
	printf("\n");
	length = sizeof(arr2) / sizeof(char);
	for(int i = 0 ; i < length ;i++){
		putchar(arr2[i]);
	}
	printf("\n");
#endif


}
