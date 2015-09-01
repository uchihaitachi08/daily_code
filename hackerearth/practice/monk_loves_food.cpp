#include<iostream>
#include<stack>
using namespace std;
int main(){
	int query,cu,ch;
	cin>>query;
	stack<int> s;
	while(query--){
		cin>>cu;
		if(cu==1){
			if(s.empty()){
				cout<<"No Food"<<endl;
			}
			else{
				cout<<s.top()<<endl;
				s.pop();
			}
		}
		else{
			cin>>ch;
			s.push(ch);
		}
	}
	return 0;
}