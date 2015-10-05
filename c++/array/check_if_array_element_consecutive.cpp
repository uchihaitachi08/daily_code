#include<iostream>
#include<map>
#include<climits>
using namespace std;
int getmin(int *arr, int n){
	int min = INT_MAX;
	for(int i=0;i<n;i++){
		if(arr[i] < min){
			min = arr[i];
		}
	}
	return min;
}
int getmax(int *arr, int n){
	int max = INT_MIN;
	for(int i=0;i<n;i++){
		if(arr[i] > max){
			max = arr[i];
		}
	}
	return max;
}
bool check_consecutive(int* arr, int n){
	int min = getmin(arr,n);
	int max = getmax(arr,n);
	map<int,int>my_map;
	if(n == max - min + 1){
		for(int i=0;i<n;i++){
			if(my_map.count(arr[i]) == 0)
				my_map[arr[i]] = 1;
			else
				return false;
		}
	}
	else
		return false;
	return true;
}
int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<check_consecutive(arr,n)<<endl;
	return 0;
}