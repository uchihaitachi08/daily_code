#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main(){
	int n;
	cin>>n;
	for(int x = 1;x<=n;x++){
		char s[100001];
		int space[100001],i,j,k;
		cin.getline(s,100001);
		space[0] = 0;
		for(i=1,j=1;s[i] != '\0';i++){
				if(s[i] == ' '){
					space[j] = i+1;
					j++;
				}
		}
		space[j] = -1;
		for(i=j-1;i>=0;i--){
			for(k = space[i];s[k] != ' ' && s[k] != '\0';k++){
				cout<<s[k];
			}
			cout<<' ';
		}
		cout<<endl;
	}
	return 0;
}