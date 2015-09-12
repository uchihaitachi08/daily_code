#include<iostream>
using namespace std;
struct node{
	int data;
	struct node* left;
	struct node* right;
};
//function to print the inorder traversal 
void inorder(struct node* root){
	if(root == NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
	return;
}

//recursive function to preorder traversal
void preorder(struct node* root){
	if(root == NULL)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
	return;
}

//recursive funtion to write postorder traversal
void postorder(struct node* root){
	if(root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
	return;
}
struct node* new_node(int data){
	struct node* new_node = new struct node;
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}
int main(){
	struct node* root = new_node(1);

	root->left = new_node(2);
	root->right = new_node(3);

	root->left->left = new_node(4);
	root->left->right = new_node(5);

	inorder(root);
	cout<<endl;
	preorder(root);
	cout<<endl;
	postorder(root);
	return 0;
}