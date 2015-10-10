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
int height(struct node* head){
	if(head == NULL)
		return 0;
	return 1+ max(height(head->left),height(head->right));
}
int diameter_tree(struct node *head,int *height){
	int lh = 0, rh = 0;
	if(head == NULL){
		*height = 0;
		return 0;
	}
	int diameter = max(diameter_tree(head->left,&lh),diameter_tree(head->right,&rh));
	*height = max(lh,rh)+1;
	diameter = max(diameter,lh+rh+1);
	return diameter;
}
int main(){
	int height = 0;
	struct node* head = new_node(1);
	head->left = new_node(2);
	head->right = new_node(3);

	head->left->left = new_node(4);
	head->left->right = new_node(5);

	head->right->left = new_node(6);
	head->right->right = new_node(7);

	cout<<diameter_tree(head,&height)<<endl;
	return 0;
}