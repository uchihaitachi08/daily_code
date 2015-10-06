#include<iostream>
#include<vector>
using namespace std;
int startind_index(int *arr, int l,int r,int x){
	if(l==r){
		if(arr[l] == x)
			return l;
		else
			return l+1;
	}
	int mid = (l+r)/2;
	if(arr[mid] >= x){
		return startind_index(arr,l,mid-1,x);
	}
	else{
		return startind_index(arr,mid + 1, r, x);
	}
}
int ending_index(int *arr, int l,int r, int x){
	if(l > r)
		return r;
	int mid = (l+r)/2;
	if(arr[mid] <= x){
		return ending_index(arr,mid + 1,r,x);
	}
	else
		return ending_index(arr,l,mid-1,x);
}

//function funda: recursive function to get the number of occurences
int recur_count(int *arr, int l, int r, int x){
	if(l==r ){
		if(arr[l] == x)
			return 1;
		else
			return 0;
	}
	int mid = (l+r)/2;
	if(arr[mid] == x){
		return 1+recur_count(arr,l,mid-1,x)+recur_count(arr,mid + 1, r,x);
	}
	else if(arr[mid] < x){
		return recur_count(arr,mid + 1,r,x);
	}
	else{
		return recur_count(arr,l,mid-1,x);
	}
}
int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int x;
	cout<<"enter the number for the occurance "<<endl;
	cin>>x;
	int i= startind_index(arr,0,n-1,x);
	int j = ending_index(arr,0,n-1,x);
	// cout<<i<<" "<<j<<endl;
	cout<<(j-i+1)<<endl;
	cout<<recur_count(arr,0,n-1,x)<<endl;
	return 0;
}