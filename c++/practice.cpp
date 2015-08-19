#include<iostream>
using namespace std;
struct node{
	int data;
	struct node* next;
};
void push(struct node** head_ref,int data){
	struct node* new_node = new struct node;
	new_node->data = data;
	new_node->next = (*head_ref);
	*head_ref = new_node;
}
void printlist(struct node* head){
	while(head != NULL){
		cout<<head->data<<"\t";
		head= head->next;
	}
}
int main(){
	struct node* head = NULL;

	push(&head,3);
	push(&head,4);
	push(&head,7);

	printlist(head);
	return 0;
}