#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
void linear(int *arr, int n, int num){
	int floor_num, ceil_num;
	if(arr[0] > num){
		cout<<"floor doesn't exist and ceil = "<<arr[0]<<endl;
	}
	else if(arr[0] == num){
		cout<<"floor = "<<arr[0]<<"ceil = "<<arr[0]<<endl; 
	}
	else{
		for(int i=1;i<n;i++){
			if(arr[i] >= num ){
				ceil_num = arr[i];
				floor_num = arr[i-1];
				break;
			}
		}
		cout<<"floor is = "<<floor_num<<" and ceil is = "<<ceil_num<<endl;
	}
}
void binary_search(int *arr, int l, int r,int num){
	if(l==r && l != 0){
		if(arr[l] >= num){
			cout<<"floor = "<<arr[l-1]<<"ceil = "<<arr[l]<<endl;
			return;
		}
		else{
			cout<<"floor = "<<arr[l]<<"ceil = "<<arr[l+1]<<endl;
			return;
		}
	}
	else if(l==r && l == 0){
		cout<<"ceil = "<<arr[l]<<"and floor does not exist "<<endl;
		return;
	}
	else{
		int mid = (l+r)/2;
		if(arr[mid] > num){
			binary_search(arr,l,mid-1,num);
		}
		else if(arr[mid] < num){
			binary_search(arr,mid +1 ,r,num);
		}
		else{
			cout<<"ceil = "<<arr[mid]<<"floor = "<<arr[mid-1]<<endl;
		}
	}
}
int main(){
	int n,num,floor_num,ceil_num;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"enter the number to generate floor and ceil"<<endl;
	cin>>num;
	sort(&arr[0],&arr[n]);
	linear(arr,n,num);
	binary_search(arr,0,n-1,num);
	return 0;
}