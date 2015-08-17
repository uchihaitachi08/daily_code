#include <iostream>
#include <string>
using namespace std;
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition (int arr[], int l, int h)
{
    int x = arr[h];    // pivot
    int i = (l - 1);  // Index of smaller element
 
    for (int j = l; j <= h- 1; j++)
    {
        // If current element is smaller than or equal to pivot 
        if (arr[j] <= x)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);  // Swap current element with index
        }
    }
    swap(&arr[i + 1], &arr[h]);  
    return (i + 1);
}
 
/* arr[] --> Array to be sorted, l  --> Starting index, h  --> Ending index */
void quickSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int p = partition(arr, l, h); /* Partitioning index */
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, h);
    }
}
int evolve_pokemon(int *arr,int end){
	int i=0,sum=0,diff;
	for(int k=end;k<=1;k++){
		diff=arr[k-1]-arr[k];
		i=i+(diff+1);
		if(i>sum)
			i=sum;
	}
	return (arr[end]+sum+2);
}
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout<<arr[i];
    cout<<endl;
}
int main()
{
	int n,*arr;
	cin>>n;
	arr=new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	quickSort(arr, 0, n-1);
    int days=evolve_pokemon(arr,n-1);
    cout<<days<<endl;
	return 0;
}

