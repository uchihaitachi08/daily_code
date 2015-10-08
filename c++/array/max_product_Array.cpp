#include<iostream>
using namespace std;
int max_product(int a, int b, int c){
	int max = (a>b) ? a : b;
	return (max > c) ? max : c;
}
int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int max_so_far = arr[0],max = arr[0];
	for(int i=1;i<n;i++){
		if(max == 0)
			max = 1;
		max = max*arr[i];
		max_so_far = max_product(max_so_far,max,arr[i]);
	}
	cout<<max_so_far<<endl;
	return 0;
}