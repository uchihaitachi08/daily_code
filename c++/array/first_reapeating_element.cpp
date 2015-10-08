// #include<iostream>
// #include<pair>
// #include<map>
#include <bits/stdc++.h>
using namespace std;
//
int main(){
	int n;
	cin>>n;

	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	map<int,int>my_map;
	for(int i=0;i<n;i++){
		if(my_map.count(arr[i]) == 0){
			my_map[arr[i]] = 1; 
		}
		else
		{
			cout<<arr[i]<<endl;
			break;
		}
	}
	return 0;
}