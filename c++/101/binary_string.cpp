#include<iostream>
#include<cmath>
#include<climits>
#include<string>
#include<cstring>
using namespace std;
void check(char* str1, char* str2){
	if(strlen(str1) != strlen(str2)){
		cout<<-1<<endl;
		return;
	}
	int i1=0,i2= 0,num = 0;
	for(int i=0;i<strlen(str1);i++){
		if(str1[i] != '1')
			i1++;
		if(str2[i] != '1')
			i2++;
		if(str1[i] != str2[i])
			num++;
	}
	if(i1 != i2 || num%2 == 1){
		cout<<-1<<endl;
		return;
	}
	cout<<num/2<<endl;
	return;
}
int main(){
	string str1,str2;
	cin>>str1>>str2;
	char *ptr1, *ptr2;
	ptr1 = new char[str1.length()];
	ptr2 = new char[str2.length()];
	strcpy(ptr1,str1.c_str());
	strcpy(ptr2,str2.c_str());
	check(ptr1,ptr2);	
	return 0;
}