#include<iostream>
using namespace std;
void swap(char *s, char *t){
	char k;
	k = *s;
	*s = *t;
	*t = k;
}
void do_swap(char *s,int n,int k,int t){
	char *end;
	end = s+n-1;
	int count = 0;
	while(t){
		if(*s == '1')
			s = s+1;
		else{
			while(*s == '0'){
				if(s == end)
					return;
				s = s+k;
				count++;
			}
			for(int i=count;i>=1;i--){
				swap(s,s-k);
				t--;
				s = s -k;
			}
			count = 0;
		}
	}
	return;
}
int main(){
	int n,k,t;
	cin>>n>>k>>t;
	char *s = new char[n];
	cin>>s;
	do_swap(s,n,k,t);
	cout<<s;
	return 0;
}