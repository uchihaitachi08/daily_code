#include<iostream>
#include<queue>
using namespace std;
struct node{
	int num;
	struct node* next;
};
int main(){
	queue<struct node*>q;
	if(q.front() == 0)
		cout<<"yolo"<<endl;
	q.pop();
	return 0;
}