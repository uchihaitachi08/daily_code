#include<iostream>
#include<cmath>
using namespace std;


int common_factor(int n,int p)
{
	

	return (p==0) ? n : common_factor(p, n%p);

}

int count_kstep(int p, int k)
{
   return (1+p*k);

}

int main()
{

	int t,n,p,k,i;
	cin>>t;

	

    for(i=1;i<=t;i++)
    {
    	cin>>n>>p>>k;
    	int hcf = common_factor(n,p);

    	if(n%p==0)
    	{
    		int a= count_kstep(p,k-1);
    		if(k>(n/p))
    			cout<<-1<<endl;
    		else
    			cout<<a<<endl;

    		
    	}
        else
        {
    	  if(hcf==0)
    	  {
    	  	if(k>n)
    	  	cout<<-1<<endl;
    	  	else	
    		cout<<k<<endl;
    	  }

    	  else 
    		{
              int new_n=n/hcf;
              int new_p=p/hcf;
              
              int m= hcf*k-(hcf-1);
                	
                
              if(k>new_n)
    			cout<<-1<<endl;
    		  else
    			cout<<m<<endl;
    		}
    	}
    }
    

	
	return 0;
}