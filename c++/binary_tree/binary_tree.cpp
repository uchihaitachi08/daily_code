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
int size(struct node* root){
	if(root == NULL)
		return 0;
	return (size(root->left)+1+size(root->right));
}
int maxdepth(struct node* root){
	if(root == NULL)
		return 0;
	return 1+(maxdepth(root->left) > maxdepth(root->right) ? maxdepth(root->left) : maxdepth(root->right));
}
void delete_tree(struct node* root){
	if(root == NULL) return;
	delete_tree(root->left);
	delete_tree(root->right);
	cout<<"deleting node "<<root->data<<endl;
	delete(root);
}

void mirror_tree(struct node* root){
	if(root == NULL)
		return;
	struct node* temp = root->left;
	root->left = root->right;
	root->right = temp;
	mirror_tree(root->left);
	mirror_tree(root->right);
	delete(temp);
	return;
}
int main(){
	struct node* root = new_node(1);

	root->left = new_node(2);
	root->right = new_node(3);

	root->left->left = new_node(4);
	root->left->right = new_node(5);

	inorder(root);
	cout<<endl;
	cout<<"maxdepth of tree "<<maxdepth(root)<<endl;
	mirror_tree(root);
	inorder(root);
	return 0;
}