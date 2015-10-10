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

bool height_balanced(struct node* head,int *height){
	if(head == NULL){
		*height = 0;
		return 1;
	}
	int lh = 0,rh =0;
	if(height_balanced(head->left,&lh) && height_balanced(head->right,&rh)){
		if(abs(lh-rh) <= 1){
			*height = max(lh,rh)+1;
			return true;
		}
		else
			return false;
	}
	else
		return false;
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
	

	cout<<height_balanced(head,&height)<<endl;
	return 0;
}