#include<iostream>
#include<cmath>
using namespace std;

int checkprime(int x)
{ 
	int flag =1;
    int i;
    for (i=2;i<x/2;i++)
    {if(x%i==0)
    {flag=0;
            return flag;
    break;}
        }
    return flag;
    }
int main()
{
    int num = pow(2,30) - 1;
    int i =1;
    int largest=0;
    for (i=2;i<=num/2;i++)
    {
        if((num%i ==0)&&(checkprime(i)))
        {
           largest=i;
        }
    }
    cout<<num<<endl;
    cout<<largest;
}