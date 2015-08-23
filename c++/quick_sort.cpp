#include<iostream>
#include<algorithm>
using namespace std;
void swap(int *a,int *b){
	int c = *a;
	*a = *b;
	*b = c;
}
int partition(int *arr,int l,int r){
	int x = arr[r];
	int i = l-1;
	for(int j=l;j<r-1;j++){
		if(arr[j]<=x){
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[r]);
	return i+1;
}
void quicksort(int *arr, int l,int r){
	if(l < r){
		int p = partition(arr,l,r);
		quicksort(arr,l,p-1);
		quicksort(arr,p+1,r);
	}
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		cout<<arr[i]<<"\t"<<endl;
	}
	quicksort(arr,0,n-1);

	for(int i=0;i<n;i++){
		cout<<arr[i]<<"\t";
	}
	return 0;
}