#include <iostream>
#include <algorithm>
#include<vector>
#include<climits>
using namespace std;
int hcf_util(int a, int b){
	if(b%a == 0)
		return a;
	return hcf_util(b%a,a);
}
int hcf(int a,int b){
	if(a == b)
		return a;
	int max = (a > b) ? a : b;
	int min = (a < b) ? a : b ;
	return hcf_util(min,max);
}

int main() {
    int n,flag = 0;
    cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }
    for(int i=0;i<n-1;i++){
    	flag = 0;
    	for(int j = i+1;j<n;j++){
    		if(hcf(arr[i],arr[j]) != 1){
    			cout<<j+1<<" ";
    			flag = 1;
    			break;
    		}
    	}
    	if(!flag)
    		cout<<-1<<" ";
    }
    cout<<-1<<endl;
    return 0;
}