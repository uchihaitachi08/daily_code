#include <iostream>
#include <string>
using namespace std;
void swap(int *num1,int *num2){
	int t;
	t=*num1;
	*num1=*num2;
	*num2=t;
}
int partition (int arr[], int front, int end)
{
    int x = arr[end];    // pivot
    int i = (front - 1);  // Index of smaller element
 
    for (int j = front; j <= end- 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);  // Swap current element with index
        }
    }
    swap(&arr[i + 1], &arr[end]);  
    return (i + 1);
}
 
void quick_partition(int arr[], int front, int end)
{
    if (front < end)
    {
        int p = partition(arr, front, end); /* Partitioning index */
        quick_partition(arr, front, p - 1);
        quick_partition(arr, p + 1, end);
    }
}
int evolve_pokemon(int *arr,int end){
	int sum=0,i=0,diff;
	for(int k=end;k>=1;k--){
		diff=arr[k-1]-arr[k];
		i=i+(diff+1);
		sum=sum+i;
	}
	if(sum>0)
		return (arr[end]+sum+2);
	else
		return (arr[end]+2);
}
int main(){
	int n,*arr,days;
	cin>>n;
	arr=new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	quick_partition(arr,0,n-1);
	days=evolve_pokemon(arr,n-1);
	cout<<days;
	return 0;
}

