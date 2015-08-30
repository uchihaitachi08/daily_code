#include<iostream>
#include<climits>
using namespace std;
struct Stacknode{
	int data;
	struct Stacknode* next;
};
struct Stacknode* new_node(int data){
	struct Stacknode* stacknode = new struct Stacknode;
	stacknode->data = data;
	stacknode->next = NULL;
	return stacknode;
}
bool isempty(struct Stacknode* root){
	return !root;
}
void push(struct Stacknode** root,int data){
	struct Stacknode* stacknode = new_node(data);
	stacknode->next = *root;
	*root = stacknode;
	cout<<data<<" is pushed to stack"<<endl;
}
int pop(struct Stacknode** root){
	if(isempty(*root)){
		cout<<"stack is empty"<<endl;
		return INT_MIN;
	}
	int data = (*root)->data;
	struct Stacknode* delete_node = *root;
	*root = (*root)->next;
	delete(delete_node);
	return data;
}
int peek(struct Stacknode* root){
	if(isempty(root)){
		return INT_MIN;
	}
	return root->data;
}

int main(){
	struct Stacknode* stack = NULL;
	char *str = "sameer";
	reverse(str);
    return 0;

}