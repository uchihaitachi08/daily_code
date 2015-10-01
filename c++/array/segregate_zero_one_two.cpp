#include<iostream>
using namespace std;
void swap(int* a,int* b){
	int t = *a;
	*a = *b;
	*b = t;
}
int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int index1 = 0;
	int index2 = n-1;
	cout<<"======================="<<endl;
	for(int i=0;i<n;i++){
		if(arr[i] == 0){
			swap(&arr[i],&arr[index1]);
			index1++;
		}
		else
			continue;
	}
	for(int i = n-1;i>=0;i--){
		if(arr[i] == 2){
			swap(&arr[i],&arr[index2]);
			index2--;
		}
		else
			continue;
	}
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}