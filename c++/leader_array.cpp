#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

//functin funda: leader is the number in array which highest to its all element to its right side
void leader(int* arr, int n){
	int max = INT_MIN;
	for(int i=n-1;i>=0;i--){
		if(arr[i] > max){
			cout<<arr[i]<<" ";
			max = arr[i];
		}
	}
	return;
}
int main(){
	int n;
	cin>>n;
	int* arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	leader(arr,n);
}