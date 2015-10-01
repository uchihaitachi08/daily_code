#include<iostream>
#include<map>
#include<string>
#include<climits>
#include<vector>
#include<cstring>
using namespace std;
// void swap ( int* a, int* b )
// {
//     int t = *a;
//     *a = *b;
//     *b = t;
// }
// int partition (int arr[],int arr2[],int arr3[],int l, int h)
// {
//     int x = arr[h];
//     int i = (l - 1);
 
//     for (int j = l; j <= h- 1; j++)
//     {
//         if (arr[j] <= x)
//         {
//             i++;
//             swap (&arr[i], &arr[j]);
//             swap(&arr2[i],&arr2[j]);
//             swap(&arr3[i],&arr3[j]);
//         }
//     }
//     swap (&arr[i + 1], &arr[h]);
//     swap (&arr2[i + 1], &arr2[h]);
//     swap (&arr3[i + 1], &arr3[h]);
//     return (i + 1);
// }
 
// /* A[] --> Array to be sorted, l  --> Starting index, h  --> Ending index */
// void quickSort(int arr[], int arr2[],int arr3[], int l, int h)
// {
//     if (l < h)
//     {        
//         int p = partition(arr,arr2,arr3, l, h); /* Partitioning index */
//         quickSort(arr,arr2,arr3, l, p - 1);  
//         quickSort(arr,arr2,arr3, p + 1, h);
//     }
// }
/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
void merge(int arr[], int arr2[],int arr3[],int l, int m, int r);

// Utility function to find minimum of two integers
int min(int x, int y) { return (x<y)? x :y; }


/* Iterative mergesort function to sort arr[0...n-1] */
void mergeSort(int arr[],int arr2[],int arr3[], int n)
{
  int curr_size;  // For current size of subarrays to be merged
                  // curr_size varies from 1 to n/2
  int left_start; // For picking starting index of left subarray
                  // to be merged

  // Merge subarrays in bottom up manner.  First merge subarrays of
  // size 1 to create sorted subarrays of size 2, then merge subarrays
  // of size 2 to create sorted subarrays of size 4, and so on.
  for (curr_size=1; curr_size<=n-1; curr_size = 2*curr_size)
  {
      // Pick starting point of different subarrays of current size
      for (left_start=0; left_start<n-1; left_start += 2*curr_size)
      {
          // Find ending point of left subarray. mid+1 is starting 
          // point of right
          int mid = left_start + curr_size - 1;

          int right_end = min(left_start + 2*curr_size - 1, n-1);

          // Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
          merge(arr,arr2,arr3,left_start, mid, right_end);
      }
  }
}

/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
void merge(int arr[],int arr2[], int arr3[], int l, int m, int r)
{
   int i, j, k;
   int n1 = m - l + 1;
   int n2 =  r - m;

   /* create temp arrays */
   int L[n1], R[n2];
   int L2[n1], R2[n2];
   int L3[n1], R3[n2];

   /* Copy data to temp arrays L[] and R[] */
   for (i = 0; i < n1; i++)
       {
           L[i] = arr[l + i];
           L2[i] = arr2[l + i];
           L3[i] = arr3[l + i];
       }
       
   for (j = 0; j < n2; j++)
       {
           R[j] = arr[m + 1+ j];
           R2[j] = arr2[m + 1+ j];
           R3[j] = arr3[m + 1+ j];
       }
       

   /* Merge the temp arrays back into arr[l..r]*/
   i = 0;
   j = 0;
   k = l;
   while (i < n1 && j < n2)
   {
       if (L[i] <= R[j])
       {
           arr[k] = L[i];
           arr2[k] = L2[i];
           arr3[k] = L3[i];
           i++;
       }
       else
       {
           arr[k] = R[j];
           arr2[k] = R2[j];
           arr3[k] = R3[j];
           j++;
       }
       k++;
   }
    /* Copy the remaining elements of L[], if there are any */
   while (i < n1)
   {
       arr[k] = L[i];
       arr2[k] = L2[i];
       arr3[k] = L3[i];
       i++;
       k++;
   }
}
int main(){
	int start_s=clock();
	int n,q,l,k,a;
	cin>>n>>q;
	vector<int>arr;
	for(int i=0;i<n;i++){
		cin>>a;
		arr.push_back(a);
	}
	int* arr1 = new int[q];
	int* arr2 = new int[q];
	int *arr3 = new int[q];
	for(int i=0;i<q;i++){
		cin>>arr1[i]>>arr2[i];
		arr3[i] = i;
	}
	
	mergeSort(arr1,arr2,arr3,q);
	

	int* arr4 = new int[q];
	l = arr1[0];
	int l_prev = arr[0];
	for(int i=0;i<q;i++){
		l = arr1[i];
		if(l > l_prev){
			for(int i=0;i<arr.size();i++){
				if(arr[i] < l)
					arr.erase(arr.begin()+i);
			}
		}
		arr4[arr3[i]] = arr[arr2[i]-1];
		l_prev = l;
		// for(int i=0;i<arr.size();i++){
		// 	cout<<arr[i]<<" ";
		// }
		// cout<<endl;
	}
	for(int i=0;i<q;i++){
		cout<<arr4[i]<<endl;
	}
	// int *arr = new int[n];
	// for(int i=0;i<n;i++){
	// 	cin>>arr[i];
	// }
	// while(q--){
	// 	int count = 0;
	// 	cin>>l>>k;
	// 	for(int i=0;i<n;i++){
	// 		if(arr[i]>=l)
	// 			count++;
	// 		if(count == k){
	// 			cout<<arr[i]<<endl;
	// 			break;
	// 		}
	// 	}
	// 	count = 0;
	// }
	int stop_s=clock();
	cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
	return 0;
}