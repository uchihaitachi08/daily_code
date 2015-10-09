#include<iostream>
#include<vector>
#include<queue>
#include<stack>
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

//preoreder, visit the root, then left and then right
void preorder(struct node* head){
	if(head == NULL)
		return;
	cout<<head->data<<" ";
	preorder(head->left);
	preorder(head->right);
	return;
}

//visit the left , right and then root
void postorder(struct node* head){
	if(head == NULL)
		return;
	postorder(head->left);
	postorder(head->right);
	cout<<head->data<<" ";
	return;
}

//size of binary tree, size of left tree + size of right tree and +1
int size_tree(struct node* head){
	if(head == NULL)
		return 0;
	return size_tree(head->left) + 1+ size_tree(head->right);
}

//visit the left, root and then right
void inorder(struct node* head){
	if(head== NULL)
		return;
	inorder(head->left);
	cout<<head->data<<" ";
	inorder(head->right);
	return;
}

int max_depth(struct node* head){
	if(head == NULL)
		return 0;
	int a1 = max_depth(head->left);
	int a2 = max_depth(head->right);
	a1 = (a1 > a2 ) ? a1 : a2;
	return a1 + 1;
}

void delete_tree(struct node** head_ref){
	if(*head_ref == NULL)
		return;
	delete_tree(&((*head_ref)->left));
	delete_tree(&((*head_ref)->right));
	delete(*head_ref);
}

//function to mirror a tree
void mirror_tree(struct node* head){
	if(head == NULL)
		return;
	struct node* temp = new struct node;
	temp = head->left;
	head->left = head->right;
	head->right = temp;
	mirror_tree(head->left);
	mirror_tree(head->right);
	return;
}

//function to print all the root to leaf paths
//utility function print the leftest path
void print_leftest(struct node* head){
	if(head == NULL)
		return;
	cout<<head->data<<" ";
	print_leftest(head->left);
	return;
}

void root_to_path(struct node* node, struct node* root){
	if(node->left == NULL || node == NULL){
		print_leftest(root);
		cout<<endl; 
		return;
	}
	root_to_path(node->left,root);
	struct node* temp = node->left;  //swapping the subtrees
	node->left = node->right;
	node->right = temp;
	root_to_path(node->left,root); // travesring the left subtree which was right tree.
	node->right = node->left;// swapping the subtrees which was previously swapped.
	node->left = temp;
	return;
}

//level order traversal using queue
void print_level_order(struct node* head){
	queue<struct node*>q;
	struct node* temp = head;
	while(temp){
		cout<<temp->data<<" ";
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
		temp = q.front();
		q.pop();
	}
	return;
}

//count leaf nodes of a tree, if node == NULL return 0, else if node->left == NULL && node->right == NULL return 1 
// leaf nodes of a tree = leaf nodes of left tree + leaf nodes of right tree

int count_leaf(struct node* head){
	if(head == NULL)
		return 0;
	if(head->left == NULL && head->right == NULL)
		return 1;
	int leaf = count_leaf(head->left)+ count_leaf(head->right);
	return leaf;
}

//function to print the level order traversal in spiral form
//the trick is to use two stacks 

void print_level_order_spiral(struct node* head){
	stack<struct node*>s1;
	stack<struct node*>s2;
	s1.push(head);
	while(!s1.empty() || !s2.empty()){
		while(!s1.empty()){
			struct node* temp = s1.top();
			s1.pop();
			cout<<temp->data<<" ";

			if(temp->left)
				s2.push(temp->left);
			if(temp->right)
				s2.push(temp->right);
		}
		while(!s2.empty()){
			struct node* temp = s2.top();
			s2.pop();
			cout<<temp->data<<" ";

			if(temp->left)
				s1.push(temp->left);
			if(temp->right)
				s1.push(temp->right);
		}
	}
}
int main(){
	struct node* head = new_node(1);
	head->left = new_node(2);
	head->right = new_node(3);

	head->left->left = new_node(4);
	head->left->right = new_node(5);

	head->right->left = new_node(6);
	head->right->right = new_node(7);

	// preorder(head);
	// cout<<endl;

	// postorder(head);
	// cout<<endl;

	// inorder(head);
	// cout<<endl;

	// cout<<size_tree(head)<<endl;
	// cout<<max_depth(head)<<endl;

	// // delete_tree(&head);
	// mirror_tree(head);
	// preorder(head);
	// cout<<endl;
	// root_to_path(head,head);

	print_level_order(head);
	cout<<endl;
	print_level_order_spiral(head);
	cout<<endl;
	return 0;
}