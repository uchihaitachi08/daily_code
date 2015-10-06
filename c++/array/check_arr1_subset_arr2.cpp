#include<iostream>
#include<map>
#include<algorithm>
#include<functional>
#include<utility>
using namespace std;
bool viahash(int *arr1, int *arr2, int n, int m){
	map<int, int>my_map;
	for(int i=0;i<n;i++){
		my_map[arr1[i]] = my_map.count(arr1[i]) + 1;
	}
	for(int i=0;i<m;i++){
		if(my_map.count(arr2[i]) == 0)
			return false;
	}
	return true;
}
void printarray(int *arr, int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
bool binary_search(int *arr, int l, int r,int x){
	if(l==r){
		if(arr[l] == x)
			return 1;
		else
			return 0;
	}
	int mid = (l+r)/2;
	if(arr[mid] == x)
		return 1;
	else if(arr[mid] > x){
		return binary_search(arr,l, mid -1, x);
	}
	else
		return binary_search(arr, mid + 1, r, x);
	return false;
}
bool viasort_binary_search(int *arr1, int *arr2,int n,int m){
	sort(&arr1[0],&arr1[n]);
	// printarray(arr1,n);
	for(int i=0;i<m;i++){
		if(!binary_search(arr1,0,n-1,arr2[i])){
			return false;
		}
	}
	return true;
}
int main(){
	int n,m;
	cin>>n>>m;
	int *arr1 = new int[n];
	int *arr2 = new int[m];
	for(int i=0;i<n;i++){
		cin>>arr1[i];
	}
	for(int i=0;i<m;i++){
		cin>>arr2[i];
	}
	cout<<(viahash(arr1,arr2,n,m) ? true : false)<<endl;
	cout<<(viasort_binary_search(arr1,arr2,n,m) ? true : false)<<endl;
	return 0;
}