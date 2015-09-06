#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main(){
	char **p = new char*[2];
	for(int i=0;i<2;i++){
		p[i] = new char[30];
	}
	p[0] = "sameer";
	p[1] = "rana";
	cout<<p[0]<<endl;
	return 0;
}