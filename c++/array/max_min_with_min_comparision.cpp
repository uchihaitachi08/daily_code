#include<iostream>
#include<vector>
using namespace std;
struct node{
	int min;
	int max;
};
//funda: first pick the initial two element if the n is even, else the first element if the n is even
//then check the numbers pairwise after that upto n-1
struct node* func(int *arr, int l,int r){
	struct node* temp = new struct node;
	if(l==r){
		temp->min = arr[l];
		temp->max = arr[r];
		return temp;
	}
	else if(r-l == 1){
		if(arr[l] > arr[r]){
			temp->max = arr[l];
			temp->min = arr[r];
		}
		else{
			temp->max = arr[r];
			temp->min = arr[l];
		}
		return temp;
	}
	else{
		int mid = (l+r)/2;
		struct node *temp_l,*temp_r;
		temp_l = func(arr,l,mid);
		temp_r = func(arr,mid+1,r);
		temp->min = (temp_l->min < temp_r->min) ? temp_l->min : temp_r->min;
		temp->max = (temp_l->max > temp_r->max) ? temp_l->max : temp_r->max;
		return temp;
	}
}
//funda: divide and conquer, divide the arry into left and right half than calculate the min and max of the half and compare them
//if size == 2 then check the min element and assign it to min else another to max, if size = 1 then min = max = that element
struct node* func2(int *arr,int n){
	struct node* temp = new struct node;
	int i;
	if(n%2){
		temp->min = arr[0];
		temp->max = arr[0];
		i = 1;
	}
	else{
		if(arr[0] > arr[1]){
			temp->max = arr[0];
			temp->min = arr[1];
		}
		else{
			temp->max = arr[1];
			temp->min = arr[0];
		}
		i = 2;
	}
	while(i<n-1){
		if(arr[i] > arr[i+1]){
			temp->max = (arr[i] > temp->max) ? arr[i] : temp->max;
			temp->min = (arr[i+1] < temp->min ) ? arr[i+1] : temp->min;
		}
		else{
			temp->max = (arr[i+1] > temp->max) ? arr[i+1] : temp->max;
			temp->min = (arr[i] < temp->min) ? arr[i] : temp->min;
		}
		i = i+2;
	}
	return temp;
}
int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	struct node *pair_new = new struct node;
	// pair_new = func(arr,0,n-1);
	pair_new = func2(arr,n);
	cout<<pair_new->min<<" "<<pair_new->max<<endl;
	return 0;
}