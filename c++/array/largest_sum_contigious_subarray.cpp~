#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int max(int a,int b){
	return a>b ? a : b;
}
int main(){
	vector<int>v;
	int n,num,so_far_max = INT_MIN,curr_max = 0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num;
		v.push_back(num);	
	}
	for(int i=0;i<n;i++){
		curr_max = max(v[i],curr_max + v[i]);
		so_far_max = (curr_max > so_far_max) ?  curr_max : so_far_max;
	}
	cout<<"the maximum sum of contigous subarray is "<<so_far_max<<endl;
	return 0;
}
