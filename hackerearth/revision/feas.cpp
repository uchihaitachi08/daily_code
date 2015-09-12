#include<iostream>
#include<string>
#include<cstring>
using namespace std;
bool check(long int** arr, long int** arr2,long int n,long int k){
	for(int i=0;i<k;i++){
		long int a = arr2[i][0],b = arr2[i][2];
		long int s = arr2[i][1];
		if(s == 1){
			arr[a][b] = arr[b][a] = 1;
			for(int i=1;i<=n;i++){
				if(arr[a][i] == 1){
					arr[i][b] = arr[b][i] = 1;
				}
			}
		}
	}
	for(int i=0;i<k;i++){
		long int a = arr2[i][0],b = arr2[i][2];
		if(arr2[i][1] == 0){
			if(arr[a][b] == 1)
				return false;
		}
	}
	return true;
}
int main(){
	int t;
	long int n,k,a,b;
	string s;
	cin>>t;
	while(t--){
		cin>>n>>k;
		long int **arr = new long int*[n+1];
		for(long int i=0;i<=n;i++){
			arr[i] = new long int[n+1];
		}
		long int **arr2 = new long int*[k];
		for(long int i=0;i<k;i++){
			arr2[i] = new long int[3];
		}
		for(long int i=0;i<k;i++){
			cin>>arr2[i][0];
			cin>>s;
			if(s == "=")
				arr2[i][1] = 1;
			else 
				arr2[i][1] = 0;
			cin>>arr2[i][2];
		}
		if(check(arr,arr2,n,k))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}