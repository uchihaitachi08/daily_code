#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[]){

	char c = 's';
	printf("%p\n",(void*)&c);
	char *str = &c;
	int i;
	printf("%s\n",str);
	return 0;
}