#include<stdio.h>
int main(){
	char fruit[][20]={"apple","banana","straway","watermale"};
	int row = sizeof(fruit)/sizeof(fruit[0]);
	int len = sizeof(fruit[0])/sizeof(char);
	for(int i = 0 ; i < row ; i++){
		
			printf("%s ",fruit[i]);
		printf("\n");
	}
}

