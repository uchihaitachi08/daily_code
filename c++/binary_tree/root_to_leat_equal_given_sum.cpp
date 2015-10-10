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

bool check_paths(struct node* head, int sum_so_far,int sum){
	if(head == NULL){
		return false;
	}
	if(head->left == NULL && head->right == NULL){
		if((head->data + sum_so_far) == sum)
			return true;
		else
			return false;
	}
	if(check_paths(head->left,(head->data+sum_so_far),sum) || check_paths(head->right,(head->data+sum_so_far),sum))
		return true;
	else
		return false;
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
	
	cout<<"enter the sum to check"<<endl;
	cin>>num;
	cout<<check_paths(head,0,num)<<endl;
	return 0;
}