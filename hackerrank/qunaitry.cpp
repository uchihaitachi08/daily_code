#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#include<cstring>
#include<ctime>
using namespace std;
void swap ( int* arr, int a,int b)
{
    int t = *(arr+a);
    *(arr+a) = *(arr+b);
    *(arr+b) = t;
}
int partition (int *arr, int l, int h)
{
    int x = arr[h];
    int i = (l - 1);
 
    for (int j = l; j <= h- 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap (arr,i,j);
        }
    }
    swap (arr,i + 1, h);
    return (i + 1);
}
 
void quickSort(int *A, int l, int h)
{
    if (l < h)
    {        
        int p = partition(A, l, h); /* Partitioning index */
        quickSort(A, l, p - 1);  
        quickSort(A, p + 1, h);
    }
}
int main(){
	int start_s=clock();
	int *arr,n;
	cin>>n;
	arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	quickSort(arr,0,n-1);
	int stop_s=clock();
	cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
	return 0;
}