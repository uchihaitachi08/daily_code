#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	int data;
	struct node* left;
	struct node* right;
};
struct node* new_node(int data){
	struct node* temp = new struct node;
	temp->data = data;
	return temp;
}

void modify(struct node* head){
	if(head == NULL)
		return;
	
}
int main(){
	struct node* head = new_node(23);
	head->left = new_node(34);
	head->right = new_node(12);
	head->left->left = new_node(13);
	head->left->right = new_node(3);
	head->right->left = new_node(67);
	head->right->right = new_node(26);

	modify(head);
}