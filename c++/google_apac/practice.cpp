#include<iostream>
#include<cmath>
#include<climits>
using namespace std;
bool check_prime(long long int num){
	for(int i=2;i<=sqrt(num);i++){
		if(num%i == 0)
			return false;
	}
	return true;
}	
void check_prime_num(long long int num,long  int* count,int *min){
	int count2 =0;
	long long int temp;
	// cout<<"sqrt num"<<sqrt(num)<<endl;
	for(int i=2;i<=sqrt(num);i++){
		if(num%i == 0){
			if(check_prime(i)){
				*count = *count+1;
				temp = num;
				while(temp%i == 0){
					count2++;
					temp = temp/i;
				}
				if(count2 < *min)
					*min = count2;
				count2 = 0;
			}
			if(check_prime(num/i) && (num/i) != i){
				*count = *count+1;
				temp = num;
				while(temp%i == 0){
					count2++;
					temp = temp/i;
				}
				if(count2 < *min)
					*min = count2;
				count2 = 0;
			}
		}
	}
}
int main(){
	int t;
	long long int num;
	int min = INT_MAX;
	long int count = 0;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>num;
		if(check_prime(num)){
			cout<<"Case #"<<i<<": Seymour"<<endl;
			continue;
		}
		check_prime_num(num,&count,&min);
		if(count%2 == 1){
			if(min == 1)
				cout<<"Case #"<<i<<": Seymour"<<endl;
			else
				cout<<"Case #"<<i<<": Laurence"<<endl;
		}
		else{
			if(min == 1)
				cout<<"Case #"<<i<<": Laurence"<<endl;
			else
				cout<<"Case #"<<i<<": Seymour"<<endl;
		}
		count = 0;
		min = INT_MAX;
	}
	return 0;
}