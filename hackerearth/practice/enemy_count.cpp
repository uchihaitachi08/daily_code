#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int t,*c,count = -1,result;
	string str;
	cin>>t;
	for(int k = 0;k<t;k++){
		cin>>str;
		c = new int[str.length()];
		for(int i=0;i<str.length();i++){
			if(str[i] == '*'){
				*(c+++count) = i;
			}
		}
		*(c+++count) = -1;
		while()
	}
	return 0;
}