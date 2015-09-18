#include<iostream>
using namespace std;
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 

int partition (int arr[],int arr2[], int l, int h)
{
    int x = arr[h];   
    int i = (l - 1);  
 
    for (int j = l; j <= h- 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;    
            swap(&arr[i], &arr[j]);
            swap(&arr2[i], &arr2[j]); 
        }
    }
    swap(&arr[i + 1], &arr[h]); 
    swap(&arr2[i + 1], &arr2[h]);  
    return (i + 1);
}
 
void quickSort(int arr[],int arr2[], int l, int h)
{
    if (l < h)
    {
        int p = partition(arr,arr2, l, h); 
        quickSort(arr,arr2 ,l, p - 1);
        quickSort(arr,arr2,p + 1, h);
    }
}
int main(){
	int t,max = 0;
	int x1,x2,y1,y2;
	cin>>t;
	int *arr1 = new int[t];
	int* arr2 = new int[t];
	for(int i=0;i<t;i++){
		cin>>x1>>y1>>x2>>y2;
		arr1[i] = x1;
		arr2[i] = x2;
	}
	
	quickSort(arr1,arr2,0,t-1);
	
	for(int i=0;i<t-1;i++){
		if(arr1[i+1] >= arr1[i] && arr1[i+1] <= arr2[i]){
			arr1[i+1] = arr1[i];
			if(arr2[i+1] <= arr2[i]){
			arr2[i+1] = arr2[i];
			}
		}
		else{
			if(max < (arr2[i] - arr1[i])){
				max = arr2[i] - arr1[i];
				x1 = arr1[i];
				x2 = arr2[i];
			}
		}
		

	}
	for(int i=0;i<t;i++){
		cout<<arr1[i]<<" "<<arr2[i]<<endl;
	}
	if(max < arr2[t-1] - arr1[t-1]){
				max = arr2[t-1] - arr1[t-1];
				x1 = arr1[t-1];
				x2 = arr2[t-1];
	}
	cout<<max<<" x1 = "<<x1<<"x2 = "<<x2<<endl;
	return 0;
}