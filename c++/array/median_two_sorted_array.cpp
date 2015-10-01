#include<iostream>
#include<vector>
using namespace std;
void find_median(int* arr1, int* arr2,int l,int r,int n,double *num){
	int j,i;
	if(l==r){
		j = n-1-l;
		*num = (arr1[l]+arr2[j])/2;
		return;
	}
	else{
		i = (l+r)/2;
		j = n-1-i;
		if(arr2[j] <= arr1[i] && arr2[j+1] >= arr1[i]){
			cout<<arr2[j]<<" "<<arr1[i]<<endl;
			*num = (arr2[j]+arr1[i])/2;
		}
		else if(arr2[j] > arr1[i])
			find_median(arr1,arr2,i+1,r,n,num);
		else
			find_median(arr1,arr2,l,i-1,n,num);
	}
	return;
}
int main(){
	int n;
	double num;
	cin>>n;
	int* arr1 = new int[n];
	int* arr2 = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr1[i];
	}
	for(int i=0;i<n;i++){
		cin>>arr2[i];
	}
	find_median(arr1,arr2,0,n-1,n,&num);
	cout<<num<<endl;
	return 0;
}