#include<iostream>
#include<string>
#include<cstring>
using namespace std;
bool check_num(char* str){
	for(int i=0;i<strlen(str);i++){
		if(str[i] == '0' || str[i] == '1' || str[i] == '8')
			continue;
		else
			return false;
	}
	return true;
}
bool check_palindrome(char* str){
	int num = strlen(str)-1;
	for(int i = 0;i<= num/2;i++){
		if(str[i] == str[num-i])
			continue;
		else
			return false;
	}
	return true;
}
int main(){
	int t;
	int n;
	string input; 
	char *str;
	cin>>t;
	while(t--){
		cin>>input;
		n = input.length();
		str = new char[n];
		strcpy(str,input.c_str());
		if(check_num(str)){
			if(check_palindrome(str)){
				cout<<"YES"<<endl;
			}
			else
			cout<<"NO"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
