#include<iostream>
using namespace std;
#define NA -1
void movetoend(int* arr,int size){
	int j=size-1;
	int i;
	for(i=size-1;i>=0;i--){
		if(arr[i] != NA){
			arr[j] = arr[i];
			j--;
		}
	}
}
void merge_arrays(int* arr, int *arr2,int m,int n){
	int i=0,j= n;
	for(int k=0;k<m;k++){
		if(arr2[i]<=arr[j]){
			arr[k] = arr2[i];
			i++;
		}
		else{
			arr[k] = arr[j];
			j++;
		}
	}
}
int main(){
	int arr[] = {1,2,NA,4,5,NA,NA,NA,78,97};
	int arr2[] = {3,18,27,127};
	movetoend(arr,10);
	merge_arrays(arr,arr2,10,4);
	cout<<endl;
	return 0;
}