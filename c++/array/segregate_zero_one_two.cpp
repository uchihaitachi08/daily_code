#include<iostream>
using namespace std;
void swap(int* a,int* b){
	int t = *a;
	*a = *b;
	*b = t;
}
void printarray(int *arr, int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
//function funda: dutch national flag problem
void sortnew(int* arr, int n){
	int lo = 0;
	int mid = 0;
	int high = n-1;
	while(mid<=high){
		
		switch(arr[mid]){
			case 0:
				swap(&arr[lo++],&arr[mid++]);
				break;
			case 1:
				mid++;
				break;
			case 2:
				swap(&arr[mid],&arr[high--]);
				break;
		}
	}
}
//just by swapping the array elements using two index
void swapsort(int *arr, int n){
	int start = 0;
	int end = n-1;
	for(int i=0;i<=end;){
		printarray(arr,n);
		if(arr[i] == 0){
			swap(&arr[i],&arr[start++]);
			i++;
		}
		else if(arr[i] == 2)
			swap(&arr[i],&arr[end--]);
		else
			i++;
	}
	return;
}
int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	// sortnew(arr,n);
	swapsort(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}