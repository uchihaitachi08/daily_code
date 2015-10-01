#include<iostream>
#include<map>
#include<string>
#include<climits>
#include<cstring>
using namespace std;
void printarray(int* arr){
	for(int i=0;i<26;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int count(int* arr1, int* arr2, int A, int B, int C){
	int sum1= 0,sum2 = 0,mis = 0,cost = 0;
	for(int i=0;i<26;i++){
		arr1[i] = arr2[i] - arr1[i];
	}
	for(int i=0;i<26;i++){
		sum1 = sum1+arr1[i];
		if(arr1[i] < 0)
			mis = mis+(-1*arr1[i]);
	}
	if(sum1 > 0)
		cost = B*sum1;
	else if(sum1 < 0){
		cost = A*(-1*sum1);
		mis = mis+sum1;
	}
	if(C < (B+A)){
		cost = cost+mis*C;
	}
	else
		cost = cost+(A+B)*mis;
	return cost;
}

int main(){
	int t;
	cin>>t;
	int A,B,C;
	string s1, s2;
	//char *ptr1,*ptr2;
	int *arr1 = new int[26];
	int *arr2 = new int[26];
	while(t--){
		for(int i=0;i<26;i++){
			arr1[i] = arr2[i] = 0;
		}
		cin>>s1>>s2;
		// ptr1 = new char[s1.length()];
		// ptr2 = new char[s2.length()];
		// strcpy(ptr1,s1.c_str());
		// strcpy(ptr2,s2.c_str());
		for(int i=0;i<s1.length();i++){
			arr1[int(s1[i])-97]++;
		}
		for(int i=0;i<s2.length();i++){
			arr2[int(s2[i])-97]++;
		}
		//printarray(arr1);
		//printarray(arr2);
		cin>>A>>B>>C;
		int max = count(arr1,arr2,A,B,C);
		cout<<max<<endl;
	}
	return 0;
}