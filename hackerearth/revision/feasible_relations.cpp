#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct cd
    {
    int left;
    int right;
};

struct cd ar[500000];
int func(int n, int element)
 {
    if(ar[n] && element<n)
        return ar[n].right;
    
    if(ar[n] && element>n)
        return ar[n].right;
    
    
}   


int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    int n,i,j;
    cin>>n;
    int **arr=new int*[n];
    for(i=0;i<n;i++)
        arr[i]=new int[2];
    
    int ar[n+1];
    
    for(i=0;i<n+1;i++)
        ar[i]=0;
    
    ar[0]=0;
    for(i=1;i<=n;i++)
        cin>>ar[i];
    
    for(i=0;i<n;i++)
    {
       cin>>arr[i][0]>>arr[i][1];
        
    }
    int edge[n]
    for(i=0;i<n;i++)
    {
        
    }
    
    
    
    return 0;
}
