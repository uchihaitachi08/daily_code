#include<iostream>
#include<string>
#include<cstring>
using namespace std;
void change(char* str){
	int count = 0;
	for(int i=0;i<=strlen(str);i++){
		if(*(str+i) == ' ')
			count++;
	}
	char **arr = new char*[count+1];
	for(int i=0;i<=count;i++){
		arr[i] = new char[30];
	}
	int i=0,k=0;
	for(int j=0;j<strlen(str);j++){
		if(*(str+j) == ' '){
			arr[i][k] = '\0';
			i++;
			k = 0;
		}
		else{
			arr[i][k] = *(str+j);
			k++;
		}
	}
	string s;
	int flag = 0;
	int max = 0;
	for(int i= 0;i<count;i++){
		for(int j = i+1;j<=count;j++){
			if(!(strcmp(arr[i],arr[j]))){
				flag++;
			}
		}
		if(max < flag){
			max = flag;
			s = arr[i];
		}
	}
	cout<<s<<endl;
}
int main(){
	int start_s=clock();
	string s;
	getline(cin,s);
	char* str = new char[s.length()];
	strcpy(str,s.c_str());
	change(str);
	int stop_s=clock();
	cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
	return 0;
}