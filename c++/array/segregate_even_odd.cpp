#include<iostream>
#include<algorithm>
using namespace std;
void swap(int* arr, int i, int j){
	int c = *(arr+i);
	*(arr+i) = *(arr+j);
	*(arr+j) = c; 
}
void segregate(int* arr, int n){
	int index = 0;
	for(int i=0;i<n;i++){
		if(arr[i]%2 == 0){
			swap(arr,i,index);
			index++;
		}
	}	
}
int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	segregate(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}