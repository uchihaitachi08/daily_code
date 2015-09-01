#include<iostream>
#include<stack>
using namespace std;
int main(){
	stack<int>*p1;
	stack<int>*p2,*p3;
	stack<int>s1;
	stack<int>s2;
	p1 = &s1;
	p2 = &s2;
	char pass_char;
	int t,b,pass,a;
	cin>>t;
	while(t--){
		cin>>pass>>b;
		p1->push(b);
		while(pass--){
			cin>>pass_char;
			if(pass_char == 'P'){
				cin>>b;
				if(!p2->empty()){
					p2->pop();
				}
				a = p1->top();
				p2->push(a);
				p1->pop();
				p1->push(b);
			}
			else{
				p3 = p1;
				p1 = p2;
				p2 = p3;
			}
		}
		cout<<"Player "<<p1->top()<<endl;
	}
	return 0;
}