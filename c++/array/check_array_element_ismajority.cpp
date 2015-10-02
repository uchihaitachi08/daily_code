#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;

int num(int count){
	int sum = 0;
	sum = sum + 1 << count;
	return sum - 1;
}
int calculate(char* ptr, int index1, int index2, int **arr2,int count,int m){
	// cout<<index1<<" "<<index2<<" "<<count<<endl;
	if((index2 - index1) == 1 || index1 >= index2)
		return 0;
	if(arr2[index1-m][index2-m] == 1)
		return 0;
	arr2[index1-m][index2-m] = 1;
	int count_new = 0;
	for(int i=index1;i<=index2;i++){
		if(ptr[i] == ';'){
			i = index1;
			break;
		}
		else
			count_new++;
	}
	for(int i=index2;i>=index1;i--){
		if(ptr[i] == ';'){
			index2 = i;
			break;
		}
		else
			count_new++;
	}
	count = count - count_new;
	int sum = num(count);
	// cout<<sum<<"before"<<endl;
	sum = sum + calculate(ptr,index1+1,index2,arr2,count,m);
	sum = sum + calculate(ptr,index1,index2-1,arr2,count,m);
	// cout<<sum<<endl;
	return sum;
}
int main(){
	int count = 0;
	int index1,index2;
	string s;
	cin>>s;
	char *ptr;
	ptr = new char[s.length()];
	strcpy(ptr,s.c_str());
	for(int i=0;i<strlen(ptr);i++){
		if(ptr[i] == ';'){
			 index1 = i;
			break;
		}
	}
	for(int i=strlen(ptr)-1;i>=0;i--){
		if(ptr[i] == ';'){
			index2 = i;
			break;
		}
	}
	for(int i=index1;i<=index2;i++){
		if(ptr[i] == '_')
			count++;
	}
	int **arr2 = new int*[index2-index1 + 1];
	for(int i=0;i<= index2-index1;i++ )
		arr2[i] = new int[index2-index1 + 1];
	cout<<calculate(ptr,index1,index2,arr2,count,index1)%1000000007<<endl;
	return 0;
}