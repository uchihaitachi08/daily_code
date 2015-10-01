#include<iostream>
#include<vector>
#include<cstdlib>
#include<climits>
#include<algorithm>
using namespace std;
//funda : sort the array
// when the sum is -ve increment from 1 else decrement from 2
int main(){
	vector<int>v;
	int n,num,index1,index2,min  = INT_MAX;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num;
		v.push_back(num);
	}
	sort(v.begin(),v.end());
	int i,j;
	// for(int i=0;i<n;i++){
	// 	cout<<v[i]<<" ";
	// }
	// cout<<endl;
	for(i=0,j=v.size()-1;i<=j;){
		num = v[i]+v[j];
		if(abs(num) < min){
			index1 = i;
			index2 = j;
			min = abs(num);
		}
		if(num < 0)
			i++;
		else
			j--;
	}
	cout<<v[index1]<<" "<<v[index2]<<endl;
	return 0;
}