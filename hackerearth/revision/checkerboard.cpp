#include<iostream>
#include<string>
#include<cstring>
using namespace std;
bool check(char** s,char** str,int n,int m){
	for(int i=0;i<32;i++){
		for(int j = 0;j<32;j++){
			if(s[n+i][m+j] != str[i][j])
				return false;
		}
	}
	return true;
}
void count(char** s, char** str,int n,int m){
	int flag = 0;
	for(int i=1;i<=n;i++){
		for(int j = 2;j<=m+1;j++){
			if(s[i][j] == '#'){
				//if(s[i-1][j+1] == '#' || s[i][j-2] == '#'){
					//continue;
				//}
				//else{
					if(check(s,str,i,j-1))
						flag++;
				//}
			}
		}
	}
	cout<<flag<<endl;
}

int main(){
	char**s = new char*[2003];
	for(int i=0;i<2003;i++){
		s[i] = new char[2003];
	}
	char**str = new char*[32];
	for(int i=0;i<32;i++){
		str[i] = new char[32];
	}
	int flag = 0;
	for(int i=0;i<32;i++){
		flag = !flag;
		for(int j=0;j<32;j++){
			if(flag){
				str[i][j] = '_';
				flag = !flag;
			}
			else{
				str[i][j] = '#';
				flag = !flag;
			}
		}
	}
	for(int i=0;i<2003;i++){
		for(int j=0;j<2003;j++){
			s[i][j] = '_';
		}
	}
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=2;j<=m+1;j++){
			cin>>s[i][j];
		}
	}
	count(s,str,n,m);
	return 0;
}