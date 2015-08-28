#include<iostream>
#include<cstring>
using namespace std;
int palindrome_count(const char* str,int l,int r,int count){
	if((r-l) == 1)
		return 1;
	count = count +  check_palindrome(str,l,r);
	count = count+ + 2;

}
int main(){
	string input;
	cin>>input;
	const char* c = input.c_str();
	int num = palindrome_count(c,0,string.length()-1,0);
}