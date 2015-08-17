#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//using namespace std;
int main(){
	int i;
	char *p="hello";
	*p='M';
	p="bye";
	for(i=0;i<=4;i++){
		printf("%c\n", 37);
	}
	return 0;
}