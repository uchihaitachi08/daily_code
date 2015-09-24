#include<iostream>
#include<vector>
using namespace std;
long int  increment(long int* count, long int nim,long int i, long int j){
    long int c = nim^i^j^(i+j);
    if(c == 0){
        *count = *count + 1;
    }
    return c;
}
void printarray(vector<long int>*v){
	for(int k=0;k<v->size();k++){
		cout<<(*v)[k]<<" ";
	}
	cout<<endl;
}
void count_sum(vector<long int>*v, long int* count,long int nim){
	long int temp, nim_temp = nim;
	if(v->size() == 1)
		return;
	for(int i=0;i<v->size()-1;i++){
		//printarray(v);
		(*v)[i] = (*v)[i]+(*v)[i+1];
		temp = (*v)[i+1];
		v->erase(v->begin()+i+1);
		nim = increment(count,nim,(*v)[i]-temp,temp);
		count_sum(v,count,nim);
		(*v)[i] = (*v)[i] - temp;
		v->insert(v->begin()+i+1,temp);
		nim = nim_temp;
	}
	return;
}
int main(){
	int t;
	long int temp,nim = 0,count = 0;
	cin>>t;
	vector<long int>v;
	for(int i=0;i<t;i++){
		cin>>temp;
		v.push_back(temp);
		nim = nim^temp;
	}
	count_sum(&v,&count,nim);
	if(!nim)
		count++;
	cout<<count<<endl;
	return 0;
}