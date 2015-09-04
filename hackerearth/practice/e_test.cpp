#include<iostream>
#include<stack>
#include<cmath>
using namespace std;
void print_ver(int**arr,int top,int bottom,int col){
	bool check = (top>bottom);
	for(int i=top;(check) ? (i>=bottom) : (i<=bottom); (check) ? i-- : i++){
		cout<<arr[i][col]<<" ";
	}
	cout<<endl;
}

void print_hor(int** arr,int left,int right,int row){
	bool check = (left > right);
	for(int i=left;(check) ? (i>=right) : (i<=right);(check) ? i-- : i++){
		cout<<arr[row][i]<<" ";
	}
	cout<<endl;
}
void print_maze(int** arr,int n){
	int i,j;
	print_ver(arr,n,0,0);
	for(i=n,j=1;i>=j;i--,j++){
		print_hor(arr,j,i,j-1);
		print_ver(arr,j,i,i);
		if(i==j)
			break;
		print_hor(arr,i-1,j,i);
		print_ver(arr,i-1,j,j);
	}
}


int main(){
	int n;
	cin>>n;
	int **arr = new int*[n];
	for(int i=0;i<n;i++){
		arr[i] = new int[n];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"========"<<endl;
	print_maze(arr,n-1);
}