#include<iostream>
using namespace std;
//funda: another dynamic programming approach 
void dpmax_sum(int *arr, int n){
	int *arr_new = new int[n];
	arr_new[0] = arr[0];
	arr_new[1] = max(arr[0],arr[1]);
	for(int i=2;i<n;i++){
		arr_new[i] = max(arr_new[i-1],arr_new[i-2]+arr[i]);
	}
	cout<<arr_new[n-1]<<endl;
	return;
}
int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int incl = arr[0];
	int excl = 0;
	int excl_new;
	for(int i=1;i<n;i++){
		// cout<<incl<<" "<<excl<<endl;
		excl_new = max(incl,excl);
		incl = excl + arr[i];
		excl = excl_new;
	}
	cout<<max(excl,incl)<<endl;//
	dpmax_sum(arr,n);
	// for(int i=0;i<n;i++){
	// 	cout<<arr[i]<<" ";
	// }
	// cout<<endl;
	return 0;
}