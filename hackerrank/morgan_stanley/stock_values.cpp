#include<iostream>
#include<map>
#include<string>
#include<climits>
using namespace std;
int mod(int a){
	if(a < 0)
		return -1*a;
	return a;
}
int sum(int* arr, int n){
	int sum = 0;
	for(int i=0;i<n/2;i++){
		sum = sum+ mod(arr[i]-arr[n-1-i]);
	}
	return sum;
}
void change(int* arr, int n,int index,int* max){
	int temp;
	if(index == n-1)
		return;
	int sum_max = sum(arr,n);
	if(sum_max > *max)
		*max = sum_max;
	
	change(arr,n,index+1,max);

	if(!(arr[index-1]%2) && !(arr[index+1]%2)){
		temp = arr[index];
		*(arr+index) = (arr[index-1]+arr[index+1])/2;
		sum_max = sum(arr,n);
		if(sum_max > *max)
			*max = sum_max;
		change(arr,n,index+1,max);
		
		*(arr+index) = temp;
	}
	return;
}
int main(){
	int t,i;
	cin>>t;
	while(t--){
		int n;
		int max = INT_MIN;
		cin>>n;
		int*arr = new int[n];
		for(i=0;i<n;i++){
			cin>>arr[i];
		}
		change(arr,n,1,&max);
		// for(i=0;i<n;i++){
		// 	cout<<arr[i]<<" ";
		// }
		cout<<max<<endl;
	}
	return 0;
}