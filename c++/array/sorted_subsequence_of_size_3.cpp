#include<iostream>
#include<vector>
using namespace std;
void printarray(int *arr, int n){
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
	int *left = new int[n];
	int *right = new int[n];
	left[0] = -1;
	int min = arr[0];
	int min_index = 0;
	for(int i=1;i<n;i++){
		if(arr[i] < min){
			min = arr[i];
			left[i] = -1;
			min_index = i;
		}

		else{
			left[i] = min_index;
		}
	}
	right[n-1] = -1;
	int max = arr[n-1];
	int max_index = n-1;
	for(int i=n-2;i>=0;i--){
		if(arr[i] > max){
			max = arr[i];
			right[i] = -1;
			max_index = i;
		}
		else{
			right[i] = max_index;
		}
	}
	for(int i=0;i<n;i++){
		if(left[i] != -1 && right[i] != -1)
			cout<<"the sorted subsequence is "<<arr[left[i]]<<" "<<arr[i]<<" "<<arr[right[i]]<<endl;
	}
	return 0;
}