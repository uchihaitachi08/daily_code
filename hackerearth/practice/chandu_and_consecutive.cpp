#include<iostream>
#include<string>
#include<cstring>
using namespace std;
void consecutive(char* str){
	char *next,*curr;
	curr = str;
	next = str+1;
	while(*(next) != '\0'){
		if(*(next) == *(curr)){
			while(*next == *curr)
				next++;
		}
		curr++;
		*curr = *next;
		next++;
	}
	*(++curr) = '\0';
}
int main(){
	int n;
	string s;
	char* str;
	cin>>n;
	while(n--){
		cin>>s;
		str = new char[s.length()];
		strcpy(str,s.c_str());
		consecutive(str);
		cout<<str<<endl;
	}
	return 0;
}