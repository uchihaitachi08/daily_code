#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t,k,rem,n;
    cin>>t;
    while(t--){
    	cin>>n;
    	k = (n/4);
    	rem = (n%4);
    	if(!rem)
    		cout<<-2*k<<" "<<-2*k<<endl;
    	else if(rem == 3)
    		cout<<-2*(k+1)<<" "<<2*(k+1)<<endl;
    	else if(rem == 2)
    		cout<<2*k+1<<" "<<2*(k+1)<<endl;
    	else
    		cout<<2*k+1<<" "<<-2*k<<endl;
    }
    return 0;
}