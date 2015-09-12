#include<iostream>
#include<climits>
#include<string>
#include<cstring>
#include<ctime>
using namespace std;
struct node{
	int data;
	struct node* next;
};
int main(){
	int n,x,y;
	cin>>n;
	int** arr = new int*[3];
	for(int i=0;i<3;i++){
		arr[i] = new int[n+1];
	}
	for(int i=1;i<=n;i++){
		arr[0][i] = i;
		cin>>arr[1][i];
	}
	struct node** a = new struct node*[n+1];
	for(int i=0;i<n-1;i++){
		cin>>x>>y;
		arr[2][x]++;
		arr[2][y]++;
		//push(a[x],y);
		//push(a[y],x);
	}
	for(int i=0;i<3;i++){
		for(int j =1;j<=n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;

}