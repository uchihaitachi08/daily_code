#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
void min_jump(int *arr, int index, int n,int jump,int *min){
	if(index == n-1){
		if(jump < *min)
			*min = jump;
	}
	else if(index >= n)
		return;
	for(int i=1;i<=arr[index];i++){
		min_jump(arr,index+i,n,jump+1,min);
	}
	return;
}
int main(){
	int n;
	int min = INT_MAX;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	min_jump(arr,0,n,0,&min);
	if(min == INT_MAX)
		cout<<"no way to jump till end"<<endl;
	else
		cout<<min<<endl;
	return 0;
}