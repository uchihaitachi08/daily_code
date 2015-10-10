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



//creating new_node and returning that to the struct node pointer
struct node* new_node(int data){
	struct node* temp = new struct node;
	temp->data = data;
	return temp;
}

bool check_elements(struct node* head, struct node* head2){
	if(head2 == NULL || head == NULL)
		return 1;
	if(check_elements(head->left,head2->left) && check_elements(head->right, head2->right)){
		if(head->data == head2->data)
			return 1;
		else
			return 0;
	}
}

bool check_subtree(struct node* head, struct node* head2){
	if(head2 == NULL)
		return 0;
	if(head2->data == head->data){
		if(check_elements(head,head2))
			return 1;
	}
	return check_subtree(head,head2->left) || check_subtree(head,head2->right);
}

int main(){
	int num;
	struct node* head = new_node(10);
	head->left = new_node(4);
	head->right = new_node(6);

	head->left->right = new_node(30);

	struct node* head2 = new_node(26);

	head2->left = new_node(11);
	head2->right = new_node(41);
	head2->right->right = new_node(4);

	head2->left->left = new_node(4);
	head2->left->right = new_node(6);
	head2->left->left->right = new_node(30);
	
	cout<<check_subtree(head,head2)<<endl;
	return 0;
}
