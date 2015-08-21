#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	int data;
	struct node* next;
};

struct node* insert(struct node** head_ref,int num){
	struct node* new_node = new struct node;
	struct node* temp = *head_ref;
	new_node->data = num;
	new_node->next = NULL;
	if(*head_ref == NULL){
		*head_ref = new_node;
		return *head_ref;
	}
	while(*head_ref == NULL){
		if((*head_ref)->data < num){
			(*head_ref) = (*head_ref)->next;
		}
		else{
			new_node->next = (*head_ref);
			(*head_ref) = new_node;
		}
	}
	return temp;
}

int main(){
	int n,num,sum = 0,min=0;
	struct node* head1 = NULL;
	struct node* head2 = NULL;
	struct node* head3 = NULL;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num;
		if(num % 3== 2)
			head2 = insert(&head2,num);
		else if(num%3 == 1)
			head1 = insert(&head1,num);
		sum = sum+num;
	}
	if(sum % 3 == 0)
		cout<<sum;
	else if(sum%3 == 2){
		if(head2){
			if(head1 && head1->next){
				min = (head2->data > (head1->data + head1->next->data)) ? (head1->data + head1->next->data) : head2->data;
				cout<<(sum - min);
			}
			cout<<(sum - head2->data);
		}
		else
			cout<<(sum - (head1->data + head1->next->data));
	}
	else{
		if(head1){
			if(head2 && head2->next){
				min = (head1->data > (head2->data + head2->next->data)) ? (head2->data + head2->next->data) : head1->data;
				cout<<(sum - min);
			}
			cout<<(sum - head1->data);
		}
		else{
			cout<<(sum - (head2->data + head2->next->data));
		}
	}	
	return 0;
}