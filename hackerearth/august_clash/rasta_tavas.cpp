#include<iostream>
#include<cmath>
using namespace std;
struct node{
	int data;
	struct node* next;
};
bool is_prime(int num){
	for(int i=2;i<=sqrt(num);i++){
		if(num % i == 0 )
			return false; 
	}
	return true;
}
struct node* append(struct node* head_ref, int data){
	struct node* new_node = new struct node;
	new_node->data = data;
	new_node->next = NULL;
	struct node* temp = head_ref;
	if (head_ref == NULL)
    {
       head_ref = new_node;
	return head_ref;
      }
	while((temp)->next != NULL){
		(temp) = (temp)->next;
	}
	(temp)->next = new_node;
	
	return head_ref;
}
int func(int n,int p,struct node* head){
	int np;
	if(p<=0)
		return 0;
	while(head != NULL){
		if(n%head->data ==0){
			np = head->data;
			break;
		}
		head = head->next;
	}
	if(np == 0)
		return 0;
	return np+func(n/np,p-np,head->next);
}
void printlist(struct node* head){
	while(head){
		cout<<head->data;
		head= head->next;
	}
	return;
}
int main(){
	int n,p,k=1,count = 0;
	cin>>n>>p;
	struct node* head = NULL;
	head = append(head,2);
	head = append(head,3);
	head = append(head,5);
	printlist(head);
	for(k=1;k<=p/6;k++){
		if(is_prime(6*k+1))
			head = append(head,6*k+1);
		if(is_prime(6*k+5))
			head = append(head,6*k+5);
	}
	for(k=1;k<=n;k++){
		if(func(k,p,head)==p)
			count = count+1;
	}
	cout<<count<<endl;
	return 0;
}