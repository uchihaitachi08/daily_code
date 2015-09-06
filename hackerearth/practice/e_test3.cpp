#include<iostream>
#include<cstring>
#include<string>
using namespace std;
void change(char* str){
	char* str2 = new char[1];
	str2[0] = '*';
	strcat(str,str2);
	char *next,*curr,*prev,*ptr;
	int count = 0,max = 0;
	next = curr = prev = str;
	for(int i = 1;*(str+i)!= '\0';i++){
		if(*(str+i) != *next){
			count = ((next - prev)/sizeof(char));
			if(max <= count){
				max = count;
				ptr = prev;
			}
			prev = curr;
			curr = next;
			next = (str+i);
		}
	}
	for(int i=0;i<max;i++){
		cout<<*(ptr+i);
	}
	cout<<endl;
}
int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	char* str = new char[s.length()];
	strcpy(str,s.c_str());
	change(str);
	return 0;
}