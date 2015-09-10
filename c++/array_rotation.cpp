#include<iostream>
#include<string>
#include<vector>
using namespace std;
void rotate_array_temp(vector<int>*arr,int n,int d){
	int* temp;
	temp = new int[d];
	for(int i=0;i<d;i++){
		temp[i] = (*arr)[i];
	}
	for(int i=d;i<n;i++){
		(*arr)[i-d] = (*arr)[i];
	}
	int j = 0;
	for(int i=n-d;i<n;i++){
		(*arr)[i] = temp[j];
		j++;
	}
}
int main(){
	static const int t[] = {12,31,3,4,56,76};
	vector<int>arr (t,t+sizeof(t)/sizeof(t[0]));
	for(int i = 0;i<=arr.size()-1;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	rotate_array_temp(&arr,arr.size(),2);
	for (int i = 0; i < arr.size() ; ++i)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}