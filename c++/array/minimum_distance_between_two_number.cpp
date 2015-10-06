#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<cstdlib>
using namespace std;
int min_distance(int *arr, int n, int x, int y){
	int prev;
	int min = INT_MAX;
	for(int i=0;i<n;i++){
		if(arr[i] == x || arr[i] == y){
			prev = i;
			break;
		}
	}
	for(int i = prev;i<n;i++){
		if(arr[i] == x || arr[i] == y){
			if(arr[i] != arr[prev] && (i - prev) < min){
				min = i - prev;
			}
			prev = i;
		}
	}
	return min;
}
int min_distance_another(int *arr, int n, int x, int y){
	int index1 = -1, index2 = -1, min = INT_MAX;
	for(int i=0;i<n;i++){
		if(arr[i] == x)
			index1 = i;
		else if(arr[i] == y)
			index2 = i;
		if(index1 != -1 && index2 != -1 && abs(index1 - index2) < min)
			min = abs(index1 - index2);
	}
	return min;
}
int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int x,y;
	cin>>x>>y;
	cout<<min_distance(arr,n,x,y)<<endl;
	cout<<min_distance_another(arr,n,x,y)<<endl;
	return 0;
}