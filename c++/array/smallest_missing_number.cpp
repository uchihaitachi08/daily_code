#include<iostream>
#include<vector>
using namespace std;
int binary_search(int *arr,int l, int r,int m){
	if(l > r)
		return r;
	int mid = (l+r)/2;
	if(arr[mid] > mid + m)
		return binary_search(arr,l,mid - 1,m);
	else
		return binary_search(arr,mid+1,r,m);
}
int main(){
	int n,m;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cin>>m;
	if(m > arr[0]+ arr[n-1] + 1)
		cout<<0<<endl;
	else{
		cout<<binary_search(arr,0,n-1,arr[0])<<endl;
	}
	return 0;
}