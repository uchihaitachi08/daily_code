#include<iostream>
#include<algorithm>
using namespace std;
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 

int partition (int arr[], int l, int h)
{
    int x = arr[h];   
    int i = (l - 1);  
 
    for (int j = l; j <= h- 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;    
            swap(&arr[i], &arr[j]);  
        }
    }
    swap(&arr[i + 1], &arr[h]);  
    return (i + 1);
}
 
void quickSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int p = partition(arr, l, h); 
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, h);
    }
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		cout<<arr[i]<<"\t"<<endl;
	}
	quickSort(arr,0,n-1);

	for(int i=0;i<n;i++){
		cout<<arr[i]<<"\t";
	}
	return 0;
}