#include<iostream>
using namespace std;
int main(){
	int i= 1;
	for(int i=0;i<10;i++){
		if(i==4)
			continue;
		cout<<i<<endl;
	}
	return 0;
}