#include<iostream>
using namespace std;
int max(int a,int b){
	return (a > b) ? a : b;
}
void printlargestsum(int *arr, int size){
	int max_so_far = arr[0];
	int curr_max = arr[0];
	for(int i=1;i<size;i++){
		curr_max = max(arr[i],curr_max + arr[i]);
		max_so_far = max(curr_max,max_so_far);
	}
	cout<<"largest sum "<<max_so_far<<endl;
	return;
}
int main(){
	int n,*arr;
	cin>>n;
	arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	printlargestsum(arr,n);
	return 0;
}