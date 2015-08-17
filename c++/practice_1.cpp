// my way to do things which involves manipulation of the head pointer itself. passing the head pointer is not the actual method
#include <iostream>
using namespace std;
struct node{
	int data;
	struct node* next;
};
void printlist(struct node* head){
	while(head->next !=NULL){
		cout<<head->data<<endl;
		head = head->next;
}
	cout<<head->data<<endl;
	cout<<"======================================="<<endl;
}
//function for inserting the node at the front
void insert_node_front(struct node* head,int data){
	while(head->next != NULL){
		head = head->next;	
}
	head->next = new struct node;
	head->next->data = data;
}

//function for inserting the node after given node
void insert_after_nth_node(struct node* head, int num, int data){
	while(num >= 1){
		head = head->next;
		num--;
}
	struct node* ptr = new struct node;
	ptr->next = head->next;
	ptr->data = data;
	head->next = ptr;
	
}

//function for inserting node at the end
struct node* insert_node_tail(struct node* head, int data){
	struct node* new_tail = new struct node;
	new_tail->data = data;
	new_tail->next = head;
	return new_tail;
}

//function for deleting node after nth node
void delete_node(struct node* head, int num){
	while(num >=1){
		head = head->next;
		num--;
}
	head->next = head->next->next;
}

//recursion solution 
void sortedIntersection(struct node *head1,struct node *head2)

{

	if(head1==NULL || head2==NULL) return;

	if(head1->data < head2->data) sortedIntersection(head1->link,head2);

	else sortedIntersection(head1,head2->link);

	if(head1->data == head2->data)

	push(&head3,head1->data);

}

int main(){
	struct node* head =  new struct node;
	struct node* second = new struct node;
	struct node* tail = new struct node;

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = tail;
	
	tail->data = 3;
	tail->next = NULL;

	printlist(head);

	insert_node_front(head,3);

	printlist(head);

	head = insert_node_tail(head,4);

	printlist(head);

	insert_after_nth_node(head, 2, 10);
	
	printlist(head);

	delete_node(head,1);

	printlist(head);
	return 0;
}
