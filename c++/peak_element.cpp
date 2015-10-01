#include<iostream>
using namespace std;
//peak element, it is the element  which is greater than it's neighbour
//do binary search and if the element is greater than it's neighbour then return 
//else if it smaller than left then peak element exist in left go to that half, vice versa
int peak(int* arr, int l,int r,int size){
	int m = (l+r)/2;
	if(m == 0 || m == size || (arr[m] > arr[m-1] && arr[m] > arr[m+1]))
		return arr[m];
	if(arr[m] < arr[m+1])
		return peak(arr,m+1,r,size);
	else
		return peak(arr,l,m-1,size);
}
int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<peak(arr,0,n-1,n-1)<<endl;
	return 0;
}