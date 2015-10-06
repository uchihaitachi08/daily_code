#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
//below is the two methods and the binary one is by me 
//function funda: just see the array which index is keeps on increasing from beginning and array index which was kept decreasing from right
// void printarray(int *arr, int n){
// 	for(int i=0;i<n;i++){
// 		cout<<arr[i]<<" ";
// 	}
// 	cout<<endl;
// }
int check_peak(int *arr, int mid, int n){
	int count = 1;
	for(int i=mid+1;i<n;i++){
		if(arr[i] <= arr[i-1])
			count++;
	}
	for(int i=mid-1;i>=0;i--){
		if(arr[i] <= arr[i+1])
			count++;
	}
	return count;
}
int binary_util(int *arr, int l,int r,int n){
	int max1,max2;
	if(l == r || (abs(l-r) == 1)){
		max1 = check_peak(arr,((arr[l] > arr[r]) ? l : r),n);
		return max1;
	} 
	int mid = (l+r)/2;
	if(arr[mid] >= arr[mid-1] && arr[mid] >= arr[mid +1]){
		max1 = check_peak(arr,mid,n);
		return max1;
	}
	else{
		max1 = binary_util(arr,mid+1,r,n);
		max2 = binary_util(arr,l,mid-1,n);
		return (max1 > max2) ? max1 : max2;
	}
}
// int binary_search(int *arr, int n){
// 	int max = binary_util(arr,0,n-1,n);
// }
int main(){
	int start_s=clock();
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	// int *incl = new int[n];
	// int *excl = new int [n];
	// incl[0] = 1;
	// int count = 1;
	// for(int i=1;i<n;i++){
	// 	if(arr[i] > arr[i-1])
	// 		count++;
	// 	else{
	// 		count = 1;
	// 	}
	// 	incl[i] = count;
	// }
	// count = 1;
	// excl[n-1] = 1;
	// for(int i=n-2;i>=0;i--){
	// 	if(arr[i] > arr[i+1])
	// 		count++;
	// 	else
	// 		count = 1;
	// 	excl[i] = count;
	// }
	// int max = INT_MIN;
	// for(int i=0;i<n;i++){
	// 	if(incl[i] + excl[i] - 1 > max)
	// 		max = incl[i] + excl[i] - 1;
	// }
	// cout<<max<<endl;
	// cout<<check_peak(arr,3,n)<<" yolo"<<endl;
	cout<<binary_util(arr,0,n-1,n)<<endl;
	int stop_s=clock();
	cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
	return 0;
}