#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define MAX 10000
using namespace std;

string add(string a,string b)
{
    int i,j;
    
    for(i=s.size()-1;i>=0;i--)
        {
        a[i] + 
    }
    
}

char * multiply(char a[],char b[])
{
    static char mul[MAX];
    char c[MAX];
    char temp[MAX];
    int la,lb;
    int i,j,k=0,x=0,y;
    long int r=0;
    long sum = 0;
    la=strlen(a)-1;
        lb=strlen(b)-1;
   
        for(i=0;i<=la;i++){
                a[i] = a[i] - 48;
        }

        for(i=0;i<=lb;i++){
                b[i] = b[i] - 48;
        }

    for(i=lb;i>=0;i--){
         r=0;
         for(j=la;j>=0;j--){
             temp[k++] = (b[i]*a[j] + r)%10;
             r = (b[i]*a[j]+r)/10;
         }
         temp[k++] = r;
         x++;
         for(y = 0;y<x;y++){
             temp[k++] = 0;
         }
    }
   
    k=0;
    r=0;
    for(i=0;i<la+lb+2;i++){
         sum =0;
         y=0;
         for(j=1;j<=lb+1;j++){
             if(i <= la+j){
                 sum = sum + temp[y+i];
             }
             y += j + la + 1;
         }
         c[k++] = (sum+r) %10;
         r = (sum+r)/10;
    }
    c[k] = r;
    j=0;
    for(i=k-1;i>=0;i--){
         mul[j++]=c[i] + 48;
    }
    mul[j]='\0';
    return mul;
}


int main() {
    char aa[100];
    char bb[100];
    string aaa,bbb;
    char *cr;
    
    int n,q,i,j,a;
    int l,r,c;
    cin>>n>>q;
    long long arr1[n]={0};
    long long arr2[n]={0};
    
    for(i=0;i<q;i++)
        {
         cin>>a>>l>>r;
        
        
        if(a==1)
            {
            cin>>c;
            for(j=l-1;j<r;j++)
                arr1[j]=arr1[j]+c;
            
        }
        if(a==2)
            {
            cin>>c;
            for(j=l-1;j<r;j++)
                arr2[j]=arr2[j]+c;
            
        }
        if(a==3)
            {
            for(j=l-1;j<r;j++)
                {
                
                aaa=to_string(arr1[j]);
                bbb=to_string(arr2[j]);
                
                strcpy(aa,aaa.c_str());
                strcpy(bb,bbb.c_str());
                cr=multiply(aa,bb);
                cout<<cr<<endl;
            }
            
        }
        
        
        
    }
    
    
   
    return 0;
}
