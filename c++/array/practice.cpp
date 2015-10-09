#include<iostream>
#include<cstdlib>
#include<string>
#include<cstring>
using namespace std;
void merge(int *arr, int l, int mid, int r){
	int n1 = mid-l+1;
	int n2 = r-mid;
	int *L = new int[n1];
	int *R = new int[n2];
	for(int i=0;i<n1;i++){
		L[i] = arr[l+i];
	}
	for(int i=0;i<n2;i++){
		R[i] = arr[mid+1+i];
	}
	int k = l,i=0,j=0;
	for(i,j;i<n1 && j<n2;){
		if(L[i] < R[j]){
			arr[k] = L[i];
			i++;
			k++;
		}
		else{
			arr[k] = R[j];
			j++;
			k++;
		}
	}
	while(i<n1){
		arr[k] = L[i];
		i++;
		k++;
	}
	while(j<n2){
		arr[k] = R[j];
		j++;
		k++;
	}
	return;
}
void merge_sort(int *arr, int l,int r){
	if(l==r)
		return;
	int mid = (l+r)/2;
	merge_sort(arr,l,mid);
	merge_sort(arr,mid+1,r);
	merge(arr,l,mid,r);
	return;
}
int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	merge_sort(arr,0,n-1);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}