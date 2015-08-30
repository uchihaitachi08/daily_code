#include<iostream>
#include<string>
using namespace std;
void magic(unsigned long int *zero,unsigned long int *one){
	unsigned long int z = 0;
	z = *zero; 
	*zero = *zero+*one;
	*one = z;
}
int main(){
	int t,n;
	unsigned long int *c = new unsigned long int[2];
	*c = 0;
	*(c+1) = 1;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			magic(c,c+1);
		}
		cout<<*(c+1)<<" "<<*c<<endl;
		*c = 0;
		*(c+1) = 1;
	}
	return 0;
}