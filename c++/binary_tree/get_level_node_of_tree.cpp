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


//creating new_node and returning that to the struct node pointer
struct node* new_node(int data){
	struct node* temp = new struct node;
	temp->data = data;
	return temp;
}

int get_level(struct node* head, int key, int level){
	if(head == NULL)
		return 0;
	if(head->data == key)
		return level;
	// cout<<head->data<<" ";
	int l1 = get_level(head->left,key,level+1);
	int l2 = get_level(head->right,key,level+1);
	if(l1)
		return l1;
	else if(l2)
		return l2;
	else
		return 0;
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
	int key;
	cout<<"enter the key of which you need level"<<endl;
	cin>>key;
	cout<<get_level(head,key,1)<<endl;
	return 0;
}
