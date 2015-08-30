#include<iostream>
#include<cmath>
using namespace std;
int check_palindrome(int num){
	int sum = 0;
	while(num/10 != 0){
		sum = sum + (num%10);
		num = num/10;
	}
	sum = sum +num;
	return sum;
}
int main()
{	
	int t;
	cin>>t;
	cout<<check_palindrome(t)<<endl;
	return 0;
}