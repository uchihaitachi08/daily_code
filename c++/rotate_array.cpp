#include<iostream>
#include<algorithm>
using namespace std;
int gcd(int a, int b){
	if(b%a == 0)
		return a;
	return (b%a,a);
}
//this function's funda is to leftrotate the array d times 
void leftrotate(int* arr, int n){
	int temp = arr[0];
	for(int i=1;i<n;i++){
		*(arr+i-1) = *(arr+i);
	}
	*(arr+n-1) = temp;
}
void rotate(int* arr, int num, int n){
	for(int i=0;i<num;i++){
		leftrotate(arr,n);
	}
}

//funda: this is the juggling algorithm, which says that move the pairs by set of gcd of d, n
void rotate_juggling(int* arr, int num, int n){
	int gcd_num = gcd(num,n);
	for(int i=0;i<gcd_num;i++){
		int temp = arr[i];
		int j = gcd_num+i;
		while(j<n){
			*(arr+j-gcd_num) = *(arr+j);
			j = j+gcd_num;
		}
		*(arr+n-1-gcd_num+1+i) = temp;
	}
}

//funda: reverse an array upto 0,d-1, then reverse d to n-1 then reverse the whole array
void swap(int* arr, int i, int j){
	int c = *(arr+i);
	*(arr+i) = *(arr+j);
	*(arr+j) = c; 
}

void reverse(int* arr, int l, int r){
	int i,j;
	for(i=l,j=r;i<=j;i++,j--){
		swap(arr,i,j);
	}
}
void rotate_reversal(int* arr, int num,int n){
	reverse(arr,0,num-1);
	reverse(arr,num,n-1);
	reverse(arr,0,n-1);
}
int main(){
	int *arr = new int[6];
	for(int i=0;i<6;i++){
		cin>>arr[i];
	}
	rotate_reversal(arr,2,6);
	for(int i=0;i<6;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}