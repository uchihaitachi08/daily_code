#include<iostream>
#include<vector>
using namespace std;
void union_arr(int* arr1,int *arr2,int n,int m){
	int i,j;
	for(i=0,j=0;i<n || j<m;){
		if(i<n && j < m){
			if(arr1[i] < arr2[j]){
				cout<<arr1[i]<<" ";
				i++;
			}
			else if(arr1[i] > arr2[j]){
				cout<<arr2[j]<<" ";
				j++;
			}
			else{
				cout<<arr2[j]<<" ";
				i++;
				j++;
			}
		}
		else if(i >= n){
			cout<<arr2[j]<<" ";
			j++;
		}
		else{
			cout<<arr1[i]<<" ";
			i++;
		}
		
	}
	cout<<endl;
}
void intersection(int *arr1,int *arr2,int n,int m){
	int i,j;
	for(i=0,j=0;i<n || j<m;){
		if(i<n && j < m){
			if(arr1[i] == arr2[j]){
				i++;
				j++;
				continue;
			}
			else if(arr1[i] < arr2[j]){
				cout<<arr1[i]<<" ";
				i++;
			}
			else{
				cout<<arr2[j]<<" ";
				j++;
			}
		}
		else if(i>=n){
			cout<<arr2[j]<<" ";
			j++;
		}
		else{
			cout<<arr1[i]<<" ";
			i++;
		}
		
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	int *arr1 = new int[n];
	int *arr2 = new int[m];
	for(int i=0;i<n;i++){
		cin>>arr1[i];
	}
	for(int i=0;i<m;i++){
		cin>>arr2[i];
	}
	union_arr(arr1,arr2,n,m);
	intersection(arr1,arr2,n,m);
	return 0;
}