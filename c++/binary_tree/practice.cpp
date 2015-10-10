#include<iostream>
#include<queue>
#include<stack>
using namespace std;
struct node{
	int num;
	struct node* next;
};
int main(){
	int p1 = 4;
	int p2 = 4;
	int *ptr = &p1;
	if(ptr == &p2)
		cout<<"yolo"<<endl;
	else
		cout<<"first"<<endl;
	return 0;
}