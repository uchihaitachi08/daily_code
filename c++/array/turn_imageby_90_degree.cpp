#include<iostream>
#include<climits>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int **arr = new int*[m];
	for(int i=0;i<m;i++){
		arr[i] = new int[n];
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<m;j++){
			cout<<arr[j][i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}