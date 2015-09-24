#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void swap(int* arr, int i, int j){
	int c = *(arr+i);
	*(arr+i) = *(arr+j);
	*(arr+j) = c; 
}
void segregate(int* arr, int n){
	
	int index = 0;
	for(int i=0;i<n;i++){
		if(arr[i] == 0){
			swap(arr,i,index);
			index++;
		}
	}
}
int main(){
	int *arr = new int[5];
	for(int i=0;i<5;i++){
		cin>>arr[i];
	}
	segregate(arr,5);
	for(int i=0;i<5;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}