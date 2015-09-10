#include<stdio.h>
#include<stdlib.h>
void change(char* str){
	*(str+3) = 'c';
}
int main(){
	char* s = (char*)malloc(sizeof(char));
	scanf("%s",s);
	change(s);
	printf("%s\n", s);
	return 0;
}