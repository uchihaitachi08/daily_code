#include<iostream>
#include<vector>
using namespace std;
//function funda: to generate the product of the array without auxiliary space 
void func(int *arr,int n){
	int temp = 1;
	int *prod = new int[n];
	prod[0] = 1;
	for(int i=1;i<n;i++){
		temp = temp*arr[i-1];
		prod[i] = temp;
	}
	temp = 1;
	for(int i=n-2;i>=0;i--){
		temp = temp*arr[i+1];
		prod[i] = prod[i]*temp;
	}
	for(int i=0;i<n;i++){
		cout<<prod[i]<<" ";
	}
}
int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	int *left = new int[n];
	int *right = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	left[0] = 1;
	for(int i=1;i<n;i++){
		left[i] = left[i-1]*arr[i-1];
	}
	right[n-1] = 1;
	for(int i=n-2;i>=0;i--){
		right[i] = right[i+1]*arr[i+1];
	}
	for(int i=0;i<n;i++){
		cout<<left[i]*right[i]<<" ";
	}
	cout<<endl;
	func(arr,n);
	cout<<endl;
	return 0;
}