#include<iostream>
using namespace std;
int main(){

	char c = 't';
	char d = 'r';
	char *const p = &c;
	p = &d;	
	return 0;
}