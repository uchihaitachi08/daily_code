#include<iostream>
#include<string>
using namespace std;
void magic(int *zero,int *one){
	int z = 0;
	z = *zero;
	*zero = *zero+*one;
	*one = z;
}
int main(){
	int t,n;
	int *c = new int[2];
	*c = 0;
	*(c+1) = 1;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			magic(c,c+1);
		}
		cout<<*c<<"\t"<<*(c+1)<<endl;
	}
	return 0;
}