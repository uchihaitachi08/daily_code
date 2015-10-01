#include<iostream>
#include<map>
#include<tr1/functional>
#include<string>
#include<cstring>
using namespace std;
int fact(int n){
	if(n==1)
		return 1;
	return n*fact(n-1);
}
int main(){
	string s;
	int *arr = new int[26];
	cin>>s;
	int total = fact(s.length());
	char* ptr = new char[s.length()];
	strcpy(ptr, s.c_str());
	for(int i=0;i<strlen(ptr);i++){
		arr[int(ptr[i])- 97]++; 
	}
	for(int i=0;i<26;i++){
		if(arr[i] > 1){
			total = total/fact(arr[i]);
		}
	}
	cout<<total<<endl;
	return 0;
}