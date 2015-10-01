#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;
int main(){
	vector<int>v;
	int n,num;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num;
		v.push_back(num);
	}
	make_heap(v.begin(),v.end());
	cout<<v.front()<<endl;
	pop_heap(v.begin(),v.end());
	v.pop_back();
	cout<<v.front()<<endl;
	pop_heap(v.begin(),v.end());
	v.pop_back();
	cout<<v.front()<<endl;
	return 0;
}