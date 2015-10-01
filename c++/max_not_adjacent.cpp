#include<iostream>
#include<algorithm>
using namespace std;
//function to print the max sum with two numbers that are not adjacent
int max(int a, int b){
	return (a>b) ? a : b;
}
void find(int* arr, int n){
	int excl = 0;
	int incl = arr[0];
	int excl_new;
	for(int i=1;i<n;i++){
		excl_new = max(incl,excl);
		incl = excl+arr[i];
		excl = excl_new;
		cout<<excl<<" "<<incl<<endl;
	}
	cout<<max(incl,excl)<<endl;
	return;
}
int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	find(arr,n);
	return 0;
}