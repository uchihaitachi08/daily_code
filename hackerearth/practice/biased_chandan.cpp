#include<iostream>
#include<stack>
using namespace std;
int main(){
	int n,b,sum = 0;
	cin>>n;
	stack<int>s;
	while(n--){
		cin>>b;
		if(b == 0){
			if(!s.empty())
				s.pop();
		}
		else
			s.push(b);
	}
	while(!s.empty()){
		sum = sum + s.top();
		s.pop();
	}
	cout<<sum<<endl;
	return 0;
}