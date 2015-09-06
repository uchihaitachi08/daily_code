#include<iostream>
#include<string>
#include<cstring>
using namespace std;
void sort(int* arr,int n){
	int j,count = 0;
	int *arr2 = new int[n];
	for(int i=0;i<n;i++){
		int k = arr[i];
		while(k%4 == 0){
			k = k/4;
			count++;
		}
		arr2[i] = count;
		count = 0;
	}
	cout<<endl;
	for(int i=1;i<=n-1;i++){
		int key = arr2[i];
		int num = arr[i];
		for( j=i-1;j>=0;j--){
			if(arr2[j] > key){
				arr2[j+1] = arr2[j];
				arr[j+1] = arr[j];
			}
			else
				break;
		}
		arr2[j+1] = key;
		arr[j+1] = num;
	}
}
int main(){
	int start_s=clock();
	int n;
	cin>>n;
	int* arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	int stop_s=clock();
	cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
	return 0;
}