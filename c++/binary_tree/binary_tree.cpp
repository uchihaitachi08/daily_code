#include<iostream>
#include<queue>
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
void delete_tree_root(struct node** root){
	delete_tree(*root);
	*root = NULL;
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
void printleftview(struct node* root){
	if(root == NULL)
		return;
		cout<<root->data<<" ";
		printleftview(root->left);
		return;
}
void root_to_path(struct node* node, struct node* root){
	if(node->left == NULL || node == NULL){
		printleftview(root);
		cout<<endl;
		return;
	}
	root_to_path(node->left,root);
	struct node* temp = node->left;
	node->left = node->right;
	node->right = temp;
	root_to_path(node->left,root);
	node->right = node->left;
	node->left = temp;
	return;
}

//function to count leaf nodes of the tree
int count_leaf_node(struct node* root){
	if(root == NULL)
		return 0;
	if(root->left == NULL && root->right == NULL)
		return 1;
	return count_leaf_node(root->left)+count_leaf_node(root->right);
}


//function for breadth first traversal of tree without queue
//(O)n^2 time complexity
//funda: first calculate the height of the tree
//the for each height call print level order and print the data if the level is one
void printgivenlevel(struct node* root, int i){
	if(root == NULL)
		return;
	if(i == 1){
		cout<<root->data<<" ";
		return;
	}
	printgivenlevel(root->left,i-1);
	printgivenlevel(root->right,i-1);
}

void printlevelorder(struct node* root){
	int height = maxdepth(root);
	for(int i=1;i<=height;i++){
		printgivenlevel(root,i);
	}
}

//function to print the breadth first travesal of the tree
//funda: print the root, and store its children to queue
//dequeue and make it the root

void printlevelorderq(struct node* root){
	struct node* temp_node = root;
	queue<struct node*> myquque;
	while(temp_node){
		cout<<temp_node->data<<" ";
		if(temp_node->left)
			myquque.push(temp_node->left);
		if(temp_node->right)
			myquque.push(temp_node->right);
		temp_node = myquque.front();
		myquque.pop();
	}
	cout<<endl;
}

//function to check children sum property of a binary tree
//property is For every node, data value must be equal to sum of data values in left and right children. Consider data value as 0 for NULL children. Below tree is an example

bool check_children_sum(struct node* root){
	int l = 0,r = 0;
	if(root == NULL || root->left == NULL || root->right == NULL)
		return 1;
	else{
		if(root->left)
			l = root->left->data;
		if(root->right)
			r = root->right->data;
		return ((root->data == l+r) && (check_children_sum(root->left)) && check_children_sum(root->right));
	}
}

//function to print the diameter of a binary tree
//go to every node, null node will return 1, other nodes will return function +1 

int diameter_tree(struct node* root){
	if(root == NULL)
		return 1;
	return diameter_tree(root->left)+diameter_tree(root->right);
}
int main(){
	struct node* root = new_node(1);

	root->left = new_node(2);
	root->right = new_node(3);
	root->right->left = new_node(7);

	root->left->left = new_node(4);
	root->left->right = new_node(5);

	inorder(root);
	cout<<"diameter of tree "<<diameter_tree(root)<<endl;
	return 0;
}