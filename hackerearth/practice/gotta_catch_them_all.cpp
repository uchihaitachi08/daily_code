#include<iostream>
#include<string>
void swap(int *l,int *r){
	int t = *l;
	*l = *r;
	*r = t;
}
int partition(int *arr,int l,int r){
	int pivot = l;
	for(int i=l;i<=r-1;i++){
		if(arr[i]<= arr[r]){
			swap(arr+pivot,arr+i);
			pivot++;
		}
		
	}
	swap(arr+pivot,arr+r);
	return pivot;
}

void quicksort(int *arr,int l,int r){
	if(l < r){
		int p = partition(arr,l,r);
		quicksort(arr,l,p-1);
		quicksort(arr,p+1,r);
	}
	else
		return;
}
bool check_sum(int *arr,int size, int num){
	int i,j;
	for(i=0,j=size-1;i<=j-1;){
		if((arr[i] + arr[j]) == num)
			return true;
		else if((arr[i]+arr[j])<num)
			i++;
		else
			j--;
	}
	return false;
}
using namespace std;
int main(){
	int *arr,n,num;
	cin>>n;
	cin>>num;
	arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	quicksort(arr,0,n-1);
	if(check_sum(arr,n,num)){
		cout<<"yes"<<endl;
	}
	else
		cout<<"no"<<endl;
	return 0;
}