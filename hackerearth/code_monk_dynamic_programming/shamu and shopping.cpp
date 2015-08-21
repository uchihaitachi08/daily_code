#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int min(int a,int b){
	if(a<b)
		return a;
	else
		return b;
}

int dp(int **a,int m){
	for(int i=1;i<m;i++){
		for(int j=0;j<=2;j++){
			if(j==0)
				a[i][j] = a[i][j]+min(a[i-1][1],a[i-1][2]);
			else if(j==1)
				a[i][j] = a[i][j]+min(a[i-1][0],a[i-1][2]);
			else 
				a[i][j] = a[i][j]+min(a[i-1][0],a[i-1][1]);
		}	
	}
	int min = a[m-1][0];
	for(int j=1;j<=2;j++){
		if(a[m-1][j] < min)
			min = a[m-1][j];
	}
	return min;
}

int main(){
	int t,m,**a;
	cin>>t;
	int result[t];
	for(int k = 0;k<t;k++){
		cin>>m;
		a = new int* [m];
		for(int i=0;i<m;i++){
			a[i] = new int[3];
		}
		for(int i=0;i<m;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}
		}
		int sum = dp(a,m);
		result[k] = sum;
	}
	for(int k= 0;k<t;k++){
		cout<<result[k]<<endl;
	}
	return 0;
}
