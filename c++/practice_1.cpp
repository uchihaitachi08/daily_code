#include <iostream>
using namespace std;
void result(int** arr, int n,int m){
	arr[n-1][0] = 0;
	for(int i=n-2;i>=0;i--){
		arr[i][0] = 1;
	}
	for(int i=1;i<m;i++){
		arr[n-1][i] = 1;
	}
	for(int i=n-2;i>=0;i--){
		for(int j=1;j<m;j++){
			arr[i][j] = arr[i+1][j]+arr[i][j-1];
		}
	}
}
int findpath(int i,int j, int** res,int n,int m){
	int sum = 0;
	sum = res[i][j]*res[n-1-(i-0)][0+m-1-j];
	return sum;
}
int main()
{
    int n,m,k,count = 0;
    cin>>n>>m>>k;
    int **res = new int*[n];
    for(int i=0;i<n;i++){
    	res[i] = new int[m];
    }
    int **arr = new int*[k];
    for(int i=0;i<k;i++){
    	arr[i] = new int[2];
    }
    for(int i=0;i<k;i++){
    	cin>>arr[i][0]>>arr[i][1];
    }
    result(res,n,m);
    for(int i=0;i<k;i++){
    	count =count+ findpath(arr[i][0]-1,arr[i][0]-1,res,n,m);
    }
    cout<<count<<endl;
    return 0;
}