#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
struct node{
	int data;
	struct node* left;
	struct node* right;
};

//creating new_node and returning that to the struct node pointer
struct node* new_node(int data){
	struct node* temp = new struct node;
	temp->data = data;
	return temp;
}

void double_tree(struct node* head){
	if(head == NULL)
		return;
	struct node* temp = head->left;
	struct node* temp2 = new struct node;
	temp2->data = head->data;
	temp2->left = temp;
	head->left = temp2;
	double_tree(head->left->left);
	double_tree(head->right);
	return;
}

void preorder(struct node* head){
	if(head == NULL)
		return;
	cout<<head->data<<" ";
	preorder(head->left);
	preorder(head->right);
	return;
}

int main(){
	int num;
	struct node* head = new_node(1);
	head->left = new_node(2);
	head->right = new_node(3);

	head->left->left = new_node(4);
	head->left->right = new_node(5);

	head->left->left = new_node(8);
	head->right->right = new_node(7);
	
	double_tree(head);

	preorder(head);
	cout<<endl;
	return 0;
}