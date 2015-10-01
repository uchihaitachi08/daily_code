#include<iostream>
#include<map>
#include<tr1/functional>
#include<string>
using namespace std;
int main(){
	int num = 0;
	hash<int>my_hash;
	if(my_hash(437) == my_hash(436+1))
		cout<<"funcker"<<endl;
	else
		cout<<"notig"<<endl;
	return 0;
}