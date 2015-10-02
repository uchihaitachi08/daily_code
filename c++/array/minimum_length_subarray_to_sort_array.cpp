#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
//int this question there is an answer in the solution which I have upvoted is much more good than previous one
//that method is I am posting in the answer below
void func(int*arr, int n){
	int max_so_far = INT_MIN,min_so_far = INT_MAX,index1,index2;
	for(int i=0;i<n;i++){
		if(arr[i] > max_so_far)
			max_so_far = arr[i];
		if(arr[i] < max_so_far)
			index2 = i;
	}
	for(int i=n-1;i>=0;i--){
		if(arr[i] < min_so_far)
			min_so_far = arr[i];
		if(arr[i] > min_so_far)
			index1 = i;
	}
	cout<<index1<<" "<<index2<<endl;
	return;
}

int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int index1,index2;
	for(int i=1;i<n;i++){
		if(arr[i] >= arr[i-1])
			continue;
		else{
			index1 = i-1;
			break;
		}
	}
	for(int i=n-2;i>=0;i--){
		if(arr[i] >arr[i+1]){
			index2 = i;
			break;
		}
	}
	int min = INT_MAX,max = INT_MIN;
	for(int i=index1;i<=index2;i++){
		if(arr[i] > max)
			max = arr[i];
		if(arr[i] < min)
			min = arr[i];
	}
	for(int i=0;i<n;i++){
		if(arr[i] > min){
			index1 = i;
			break;
		}
	}
	for(int i=n-1;i>=0;i--){
		if(arr[i] < max){
			index2 = i;
			break;
		}
	}
	func(arr,n);
	cout<<index1<<" "<<index2<<endl;
	return 0;

}