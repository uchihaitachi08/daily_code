#include<iostream>
#include<string>
#include<cstring>
using namespace std;
void swap(char* str1,char* str2){
	char c;
	c = *str1;
	*str1 = *str2;
	*str2 = c;
}
void reverse(char* str){
	for(int i=0;i<=((strlen(str)-1)/2);i++){
		swap(str+i,str+strlen(str)-1-i);
	}
}
int main(){
	string *c;
	char *str;
	int n,flag = 0;
	string result;
	cin>>n;
	c = new string[n];
	for(int i =0;i<n;i++){
		cin>>c[i];
	}
	for(int i=0;i<n-1;i++){
		str = new char[c[i].length()];
		strcpy(str,c[i].c_str());
		reverse(str);
		for(int j=i+1;j<n;j++){
			if(str == c[j]){
				result = c[j];
				flag = 1;
				break;
			}
		}
		if(flag)
			break;
	}
	cout<<strlen(str)<<" "<<*(str+(strlen(str)-1)/2)<<endl;
	return 0;

}
