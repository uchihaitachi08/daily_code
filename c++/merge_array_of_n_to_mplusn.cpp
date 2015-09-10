#include<iostream>
using namespace std;
#define NA -1
void shift(int* arr, int n){
	int k = n-1;
	for(int i=n-1;i>=0;i--){
		if(arr[i] != -1){
			arr[k] = arr[i];
			k--;
		}
	}
}
void push(int* arr,int* arr2,int n1,int n2){
	int k = n2;
	int l = 0;
	for(int i=0;i<n1;i++){
		if(arr[k] < arr2[l]){
			arr[i] = arr[k];
			k++;
		}
		else{
			arr[i] = arr2[l];
			l++;
		}
	}
}
int main(){
	int arr[] = {1,2,NA,NA,NA,NA,22,34,67};
	int arr2[] = {12,23,78,112};
	shift(arr,9);
	push(arr,arr2,9,4);
	for(int i=0;i<9;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}