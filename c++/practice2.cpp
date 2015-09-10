#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string change(char* str){
	*(s+3) = 'c';
	return s;
}
int main(){
	char* s = (char*)malloc(sizeof(char));
	scanf("%s",s);
	change(s);
}