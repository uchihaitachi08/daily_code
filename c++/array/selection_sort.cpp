#include<iostream>
#include<vector>
#include<climits>
using namespace std;
void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}
void printarray(int *arr , int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int min,min_index;
	for(int i=0;i<=n-2;i++){
		min = INT_MAX;
		for(int j=i;j<n;j++){
			if(arr[j] < min){
				min_index = j;
				min = arr[j];
			}
		}
		swap(&arr[i],&arr[min_index]);
		printarray(arr,n);
	}
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}