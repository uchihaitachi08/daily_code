#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<climits>
using namespace std;
struct node{
	int data;
	struct node* left;
	struct node* right;
	struct node* nextright;
};



//creating new_node and returning that to the struct node pointer
struct node* new_node(int data){
	struct node* temp = new struct node;
	temp->data = data;
	return temp;
}

void connect_nodes(struct node* head){
	queue<struct node*>my_q;
	struct node* temp = head;
	struct node* temp2 = NULL;
	my_q.push(temp2);
	while(!my_q.empty()){
		if(temp){
			temp->nextright = my_q.front();
			if(temp->left)
				my_q.push(temp->left);
			if(temp->right)
				my_q.push(temp->right);
		}
		else{
			my_q.push(temp2);
		}
		temp = my_q.front();
		my_q.pop();
	}
}

void print_right_util(struct node* head){
	if(head == NULL)
		return;
	cout<<head->data<<" ";
	print_right_util(head->nextright);
	return;
}
void print_right(struct node* head){
	if(head == NULL)
		return;
	print_right_util(head);
	cout<<endl;
	print_right(head->left);
	return;
}
int main(){
	int num;
	struct node* head = new_node(26);
	head->left = new_node(10);
	head->right = new_node(3);

	head->left->left = new_node(4);
	head->left->right = new_node(6);

	head->right->left = new_node(3);
	head->right->right = new_node(7);
	
	connect_nodes(head);
	print_right(head);
	return 0;
}
