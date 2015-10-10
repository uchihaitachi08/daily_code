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
	struct node* next;
};



//creating new_node and returning that to the struct node pointer
struct node* new_node(int data){
	struct node* temp = new struct node;
	temp->data = data;
	return temp;
}


int main(){
	int num;
	

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
