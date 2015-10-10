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
};
int height(struct node* head){
	if(head == NULL)
		return 0;
	return 1+ max(height(head->left),height(head->right));
}

int get_width(struct node* head, int level){
	if(head == NULL)
		return 0;
	if(level == 1)
		return 1;
	else{
		return get_width(head->left,level-1) + get_width(head->right,level-1);
	}
}

//this one is using level order traversal 
int get_max_width(struct node* head){
	int max_width = INT_MIN;
	for(int i=1;i<=height(head);i++){
		int leve_width = get_width(head,i);
		if(max_width < leve_width)
			max_width = leve_width;
	}
	return max_width;
}

//creating new_node and returning that to the struct node pointer
struct node* new_node(int data){
	struct node* temp = new struct node;
	temp->data = data;
	return temp;
}




//elegant method to count the number of nodes in each level
// make an array of size of the height of the tree and store the number of node in each level
void preorder(struct node* head,int *arr, int level){
	if(head == NULL)
		return;
	arr[level-1] = arr[level-1]+1;
	preorder(head->left,arr,level+1);
	preorder(head->right,arr,level+1);
	return;
}


int main(){
	int num;
	struct node* head = new_node(1);
	head->left = new_node(2);
	head->right = new_node(3);

	head->left->left = new_node(4);
	head->left->right = new_node(5);

	head->right->left = new_node(8);
	head->right->right = new_node(7);
	int height_tree = height(head);
	int *arr = new int[height_tree];

	preorder(head,arr,1);
	int max = INT_MIN;
	for(int i=0;i<height_tree;i++){
		if(max < arr[i])
			max = arr[i];
	}
	cout<<max<<endl;

	cout<<get_max_width(head)<<endl;
	return 0;
}
