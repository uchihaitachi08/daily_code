// #include<iostream>
// #include<stack>
// using namespace std;
// int main(){
// 	int n;
// 	cin>>n;
// 	int *arr = new int[n];
// 	for(int i=0;i<n;i++){
// 		cin>>arr[i];
// 	}
// 	int next;
// 	stack<int>s;
// 	s.push(arr[0]);
// 	for(int i=1;i<n;i++){
// 		next = arr[i];
// 		// cout<<next<<endl;
// 		while(s.top() < next){
// 			cout<<s.top()<<"==>"<<next<<endl;
// 			s.pop();
// 			if(s.empty())
// 				break;
// 		}
// 		// cout<<"yello"<<endl;
// 		s.push(next);
// 	}
// 	while(!s.empty()){
// 		cout<<s.top()<<"==>"<<-1<<endl;
// 		s.pop();
// 	}
// 	return 0;
// }
#include<iostream>
#include<stack>
using namespace std;
 
void findNGE(int *a,int n){
    stack<int> s;
    s.push(a[n-1]);
 
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && a[i] >= s.top()){
            s.pop();
        }
        if(s.empty()){
            cout<<a[i]<<" ---> -1"<<endl;
        }
        else{
            cout<<a[i]<<" ---> "<<s.top()<<endl;
        }
        s.push(a[i]);
    }
}
 
int main(){
    int a[] = {11,13,2,21};
    int sz = sizeof(a)/sizeof(a[0]);
    findNGE(a,sz);
    return 0;
}
//function: both the methods are good just the first one is doing it from the first 
//second one is pushing into stack from the end