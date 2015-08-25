#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[]){

	int i=123;
	float x = 12.0,y = -3.3;
	printf(":%6d %7.0f %10.1e:\n\n",i,x,y );
	printf(":%-6d %-7.0f %-10.1e:\n\n",i,x,y );
	printf(":%+6d %+7.0f %+10.1e:\n\n",i,x,y );
	printf(":%-+6d %-+7.0f %-+10.1e:\n\n",i,x,y );

	return 0;
}