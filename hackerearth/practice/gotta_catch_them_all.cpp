#include<iostream>
#include<string>
using namespace std;
int max(int a,int b){
	return ((a>b) ? a: b);
}
void merge(int a[], int l, int m, int r){
	int n1 = m-l+1;
	int n2 = r - m;
	//cout<<"n1 = "<<n1<<"n2 = "<<n2<<endl;
	int L[n1],R[n2];
	for(int i = 0;i<n1;i++){
		L[i] = a[l+i];
	}
	for(int i = 0;i<n2;i++){
		R[i] = a[m+1+i];
	}
	int i = 0;
	int j = 0;
	int k = l;

	while(i< n1 && j< n2){
		if(L[i] <= R[j]){
			a[k] = L[i];
			i++;
		}
		else{
			a[k] = R[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		a[k] = L[i];
		i++;
		k++;
	}
	while(j<n2){
		a[k] = R[j];
		j++;
		k++;
	}
}
void merge_sort(int a[],int l,int r){
	if(l < r){
		//cout<<"now l is = "<<l<<endl;
		int m = l+(r-l)/2; //passing the middle element
		merge_sort(a,l,m);	//recursively calling the merge sort formula
		merge_sort(a,m+1,r);
		merge(a,l,m,r);//finally merging the arrays
	}
}
int main(){
	int n,*arr,max_sum = 0,count = 1;
	cin>>n;
	arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	merge_sort(arr,0,n-1);	
	max_sum = arr[n-1]+1;
	for(int i=n-2;i>=0;i--){
		max_sum = max(max_sum,(count+arr[i]+1));
		count++;
	}
	cout<<max_sum+1<<endl;
	return 0;
}