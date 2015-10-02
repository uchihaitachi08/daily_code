#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
//int this question there is an answer in the solution which I have upvoted is much more good than previous one
//that method is I am posting in the answer below

int main(){
	int n,sum = 0;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sum = sum + arr[i];
	}	
	// cout<<sum<<"yolo"<<endl;
	int left_sum = 0;
	int right_sum;
	for(int i=0;i<n;i++){
		right_sum = sum - arr[i];
		sum = sum - arr[i];
		// cout<<right_sum<<" "<<left_sum<<endl;
		if(left_sum == right_sum)
			cout<<i<<"equilibrium index"<<endl;
		left_sum = left_sum + arr[i];
	}
	return 0;

}