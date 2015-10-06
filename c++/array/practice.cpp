#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
	for(int i=0;i<10000;i++){
		cout<<rand()%10000<<" ";
	}
	return 0;
}