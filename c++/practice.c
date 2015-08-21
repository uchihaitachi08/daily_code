#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	char *c = (char *)malloc(sizeof(char)*n);
	scanf("%s",c);
	printf("%s\n", c);
	return 0;
}