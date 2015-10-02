#include<iostream>
#include<algorithm>
#include<map>
#include<functional>
#include<utility>
using namespace std;
//function funda: just map the elements which are present in the map
void viamap(int *arr, int n){
	map<int,int>my_map;
	for(int i=0;i<n;i++){
		if(my_map.count(arr[i]) == 0){
			my_map[arr[i]] = 1;
		}
		else
			cout<<arr[i]<<" ";
	}
	cout<<endl;
}
//make the array index element negative if it's not visited
//if it's already negative then just print that element
void viaindex(int *arr, int n){
	for(int i=0;i<n;i++){
		if(arr[abs(arr[i])] > 0){
			arr[abs(arr[i])] = arr[abs(arr[i])]*-1;
		}
		else{
			cout<<abs(arr[i])<<" ";
		}
	}
}
// void viaxor(int *arr, int n){
// 	int num = 0;
// 	for(int i=0;i<n;i++){
// 		num = num^arr[i];
// 	}
// 	cout<<num<<endl;
// }
int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	viamap(arr,n);
	viaindex(arr,n);
	// viaxor(arr,n);
	return 0;
}