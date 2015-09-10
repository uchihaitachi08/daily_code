#include<iostream>
#include<string>
#include<cstring>
using namespace std;
void count(char* str){
	long int num1 = 0,num2 = 0;
	double flag = 0;
	for(long int i = 0;i<strlen(str);i++){
		if(*(str+i) == 'w'){
			num1++;
			num2++;
			flag = flag + 1;
		}
		else if(*(str+i) == 'v'){
			num2++;
			flag = flag + 0.5;
		}
		else{
			double fraction = flag - ((long)flag);
			if(fraction == 0.5)
				flag = flag + 0.5;
		}
	}
	double fraction = flag - ((long)flag);
			if(fraction == 0.5)
				flag = flag + 0.5;
	cout<<(strlen(str)-num2+flag)<<" "<<(strlen(str)+num1)<<endl;
}
int main(){
	long int n;
	cin>>n;
	char* str = new char[n];
	cin>>str;
	count(str);
	return 0;
}