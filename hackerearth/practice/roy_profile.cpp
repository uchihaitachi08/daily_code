#include<iostream>
using namespace std;
int main()
{
	int l,t,w,h;
	cin>>l;
	cin>>t;
	while(t--){
		cin>>w>>h;
		if(w>l && h>l){
			
				cout<<"CROP IT"<<endl;
		}
		else{
			if(w==h)
				cout<<"ACCEPTED"<<endl;
			else
			cout<<"UPLOAD ANOTHER"<<endl;
		}
	}
	return 0;
}