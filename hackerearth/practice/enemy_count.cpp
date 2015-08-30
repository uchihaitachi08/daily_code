#include<iostream>
#include<string>
using namespace std;
int main(){
	int n,count = 0,*c,result = 0;
	string str;
	cin>>n;
	for(int k = 0;k<n;k++){
		cin>>str;
		c = new int[str.length()];
		int *ptr = c;
		*ptr = 0;
		ptr++;
		for(int i=0;i<str.length();i++){
			if(str[i] == '*'){
				*ptr = i;
				ptr++;
			}
		}
		*ptr = str.length();
		while(*c != str.length()){
			for(int i = *c;i<=*(c+1);i++){
				if(str[i] == 'X'){
					count = 0;
					break;
				}
				if(str[i] == 'O'){
					count++;
				}
			}
			result = result + count;
			count = 0;
			c++;
		}
		cout<<result<<endl;
		result = 0;
		//output[k] = result;
		//result = 0;
	}

	//for(int k = 0;k<n;k++){
		//cout<<output[k]<<endl;
	//}
	return 0;
}