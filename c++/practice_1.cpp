#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
int main(){
	int n,count = 0,t;
	float d1,d2;
	cin>>t;
	int *result = new int[t];
	for(int k=0;k<t;k++){
		cin>>n;
		int **a = new int*[n];
		for(int i=0;i<n;i++){
			a[i] = new int[2];
		}
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1];
		}
		for(int i=0;i<=n-2;i++){
			for(int j=(i+1);j<n;j++){
				d1 = a[i][0]-a[j][0];
				d2 = a[i][1]-a[j][1];
				if((d1/d2) < 0)
					count++;
			}
		}
		result[k] = count;
		count = 0;
	}
	for(int i=0;i<t;i++){
		cout<<result[i]<<endl;
	}
	return 0;
}