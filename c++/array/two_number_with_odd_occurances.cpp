#include<iostream>
#include<algorithm>
using namespace std;
void printnumbers(int *arr, int n){
	int xor2 = arr[0];
	int set_bit_no;
	int x = 0;
	int y = 0;
	for(int i=1;i<n;i++){
		xor2 = xor2^arr[i];//make xor of every element in the end that two number will remain which are odd 
	}
	set_bit_no = xor2 & ~(xor2 - 1);//set_bit_no is the number which is storing the right most 1 of the xor number
	for(int i=0;i<n;i++){
		if(arr[i] & set_bit_no)//checking the two number to see if the set_bit_no of arr[i] is = set_bi_no or not
			x = x^arr[i];
		else
			y = y^arr[i];
	}
	cout<<x<<" "<<y<<endl;
}
int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	printnumbers(arr,n);
	return 0;
}