#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int given_sum;
	cin>>given_sum;
	int flag = 0;
	int curr_sum = arr[0];
	int start_index = 0;
	for(int i=1;i<n;i++){
		curr_sum = curr_sum+ arr[i];
		while(curr_sum > given_sum){
			curr_sum = curr_sum - arr[start_index];
			start_index++;
		}
		if(curr_sum == given_sum && start_index < n){
			cout<<"sum found between "<<start_index<<" "<<i<<endl;
			flag = 1;
			break;
		}
	}
	if(!flag)
		cout<<"no subarrays found"<<endl;
	return 0;
}