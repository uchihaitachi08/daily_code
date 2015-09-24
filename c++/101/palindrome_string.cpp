#include<iostream>
#include<cmath>
#include<climits>
#include<string>
#include<cstring>
using namespace std;
bool check_palindrome(char* str,long  int l,long int r){
	long int num;
	int* arr = new int[26];
	for(long int i=l;i<=r;i++){
		num = int(str[i]) - 97;
		arr[num] = !arr[num];
	}
	num = 0;
	for(long int i=0;i<26;i++){
		if(arr[i])
			num++;
		if(num > 1)
			return false;
	}
	return true;
}
long int hcf(long int a,long int b){
	if(b%a == 0)
		return a;
	return hcf(b%a,a);
}
void count(char* ptr){
	long int count = 0;
	for(long int i=0;i<strlen(ptr);i++){
		for(long int j = i;j<strlen(ptr);j++){
			if(check_palindrome(ptr,i,j)){
				count++;
			}
		}
	}
	long int max = ((strlen(ptr)*(strlen(ptr)+1))/2);
	if(max == count){
		cout<<1<<"/"<<1<<endl;
		return;
	}
	else	
		cout<<count/hcf(count,max)<<"/"<<max/hcf(count,max)<<endl;
	return;
}	
int main(){
	long int t;
	cin>>t;
	string str;
	char* ptr;
	while(t--){
		cin>>str;
		ptr = new char[str.length()];
		strcpy(ptr,str.c_str());
		count(ptr);
	}	
	return 0;
}