#include<iostream>
using namespace std;
void printarray(long int* arr, long int t){
    for(int i=0;i<t;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
long int  increment(long int* arr,long int* count, long int nim,long int i, long int j,long int t){
    long int c = nim^i^j^(i+j);
    if(c == 0){
        *count = *count + 1;
        cout<<"yo"<<endl;
        printarray(arr,t);
    }
    return c;
}

void count_sum(long int* arr, long int* count,long int t,long int nim){
    long int temp, nim_temp = nim;
    int flag = 0;
    for(int i=0;i<=t-2;i++){
        if(arr[i] != -1){
            for(int j=i+1;j<=t-1;j++){
                if(arr[j] != -1 && !flag){
                    flag = 1;
                    arr[i] = arr[i]+ arr[j];
                    temp = arr[j];
                    arr[j] = -1;
                    nim = increment(arr,count,nim,arr[i]-temp, temp,t);
                    //printarray(arr,t);
                    count_sum(arr,count,t,nim);
                    arr[j] = temp;
                    arr[i] = arr[i] - temp;
                    nim = nim_temp;
                }
            }   
        }
        flag = 0;
    }
}
int main()
{
    int t;
    cin>>t;
    long int count  = 0;
    long int *arr = new long int[t];
    long int nim =0;

    for(int i=0;i<t;i++)
    {
        cin>>arr[i];
        nim= nim^arr[i];
    }
    count_sum(arr,&count,t,nim);
    if(!nim)
        count++;
    cout<<count<<endl;
    return 0;
}