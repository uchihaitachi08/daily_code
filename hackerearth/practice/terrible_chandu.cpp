#include<iostream>
#include<string>
#include<cstring>
using namespace std;
void reverse(char* str){
	for(int i= strlen(str) - 1;i >= 0;i--){
		cout<<*(str+i);
	}
	cout<<endl;
}
int main(){
	string s;
	char *str;
	int n;
	cin>>n;
	while(n--){
		cin>>s;
		str = new char[s.length()];
		strcpy(str,s.c_str());
		reverse(str);
	}
	return 0;
}