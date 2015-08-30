#include<iostream>
#include<string>
#include<cmath>
using namespace std;
void merge(long int a[],long int l,long  int m,long int r){
	long int n1 = m-l+1;
	long int n2 = r - m;
	//cout<<"n1 = "<<n1<<"n2 = "<<n2<<endl;
	long int L[n1],R[n2];
	for(long int i = 0;i<n1;i++){
		L[i] = a[l+i];
	}
	for(long int i = 0;i<n2;i++){
		R[i] = a[m+1+i];
	}
	long int i = 0;
	long int j = 0;
	long int k = l;

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
void merge_sort(long int a[],long int l,long int r){
	if(l < r){
		//cout<<"now l is = "<<l<<endl;
		long int m = l+(r-l)/2; //passing the middle element
		merge_sort(a,l,m);	//recursively calling the merge sort formula
		merge_sort(a,m+1,r);
		merge(a,l,m,r);//finally merging the arrays
	}
}
int main(){
	 long int*c;
	 long int n,k,flag = 0;
	 long int result;
	cin>>n>>k;
	c = new long int[n];
	for (long int i=0;i<n;i++){ 
		cin>>c[i];
	}
	merge_sort(c,0,n-1);
	for(long int i=0;i<n-1;i++){
		if((c[i+1] - c[i]) > k){
			result = c[i];
			flag = 1;
			break;
		}
	}
	if(!flag)
		result = c[n-1];
	cout<<result<<endl;
	return 0;
}
