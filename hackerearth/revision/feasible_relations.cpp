#include<iostream>
#include<string>
#include<cstring>
using namespace std;
bool check(long int* arr,long  int** arr2,long int k){
	for(long int i=0;i<k;i++){
		if(arr2[i][1] == 1){
			arr[arr2[i][0]-1] = 1;
			arr[arr2[i][2]-1] = 1;
		}
	}
	for(long int i=0;i<k;i++){
		if(arr2[i][1] == 0){
			if((arr[arr2[i][0]-1] != -1) && (arr[arr2[i][2]-1] != -1) && (arr[arr2[i][0]-1] == arr[arr2[i][2]-1]))
				return false;
		}
	}
	return true;
}

int main(){
	int t;
	long int n,k;
	string s;
	cin>>t;
	while(t--){
		cin>>n>>k;
		long int* arr = new long int[n];
		for(long int i=0;i<n;i++)
			arr[i] = -1;
		long int **arr2 = new long int*[k];
		for(long int i=0;i<k;i++){
			arr2[i] = new long int[3];
		}
		for(long int i=0;i<k;i++){
			cin>>arr2[i][0];
			cin>>s;
			if(s == "=")
				arr2[i][1] = 1;
			else if(s == "!=")
				arr2[i][1] = 0;
			cin>>arr2[i][2];
		}
		if(check(arr,arr2,k))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;	
}