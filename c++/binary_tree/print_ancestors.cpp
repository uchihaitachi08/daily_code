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

int print_ancestors(struct node* head, int key){
	if(head == NULL)
		return 0;
	if(head->data == key){
		return 1;
	}
	if(print_ancestors(head->left,key) || print_ancestors(head->right,key)){
		cout<<head->data<<" ";
		return 1;
	}
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
	cout<<"enter the number's ancestors to print "<<endl;
	cin>>key;
	int get = print_ancestors(head,key);
	return 0;
}
