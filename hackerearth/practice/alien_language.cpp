#include<iostream>
#include<string>
using namespace std;

int main(){
	int arr[26] = {0};
	string text,pattern;
	int n,flag = 0;
	cin>>n;
	while(n--){
		cin>>text;
		cin>>pattern;
		for(int i=0;i<text.length();i++){
			arr[text[i]-97] = arr[text[i]-61] +1;
		}
		for(int i=0;i<pattern.length();i++){
			if(arr[pattern[i]-97]){
				flag = 1;
				break;	
			}
		}
		if(flag)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		flag  = 0;
		for(int i=0;i<26;i++){
			arr[i] = 0;
		}
	}
	return 0;
}
