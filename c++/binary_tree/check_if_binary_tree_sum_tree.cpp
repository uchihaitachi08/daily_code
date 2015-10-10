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

bool check_sum_tree(struct node* head,int *sum){
	int ls = 0;
	int rs = 0;
	if(head == NULL)
		return true;
	if(head->left == NULL && head->right == NULL){
		*sum = head->data;
		return true;
	}

	if(check_sum_tree(head->left,&ls) && check_sum_tree(head->right,&rs)){
		if(head->data == (ls+rs)){
			*sum = 2*(head->data);
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

int main(){
	int num;
	struct node* head = new_node(26);
	head->left = new_node(10);
	head->right = new_node(3);

	head->left->left = new_node(4);
	head->left->right = new_node(6);

	head->right->left = new_node(3);
	// head->right->right = new_node(7);
	
	cout<<check_sum_tree(head,&num)<<endl;
	return 0;
}
