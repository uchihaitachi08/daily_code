#include<iostream>
#include<vector>
#include<climits>
using namespace std;
struct node{
	int min;
	int max;
};
//funda: deduce the minimum element so far and according to that generate the max diff so far
int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int min_so_far = arr[0];
	int max_diff_so_far = INT_MIN;
	for(int i=1;i<n;i++){
		if(arr[i] < min_so_far){
			min_so_far = arr[i];
		}
		if((arr[i] - min_so_far) > max_diff_so_far){
			max_diff_so_far = arr[i] - min_so_far;
		}
	}
	cout<<max_diff_so_far<<endl;
	return 0;
}