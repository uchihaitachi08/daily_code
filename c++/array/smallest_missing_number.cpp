#include<iostream>
#include<vector>
using namespace std;
int binary_search(int *arr,int l, int r,int m,){
	if(l==r){
		return mid + m;
	}
	int mid = (l+r)/2;
	if(arr[mid] == mid + m)
		binary_search(mid+1,r);
	else{
		if(arr[mid] > mid + m){
			binary_search(l,mid-1);
		}
	}
}
int main(){
	int n,m;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cin>>m;
	if(m != arr[n-1] - arr[0] + 1)
		cout<<0<<endl;
	else{
		cout<<binary_search(arr,0,n-1,arr[0])<<endl;
	}
	return 0;
}