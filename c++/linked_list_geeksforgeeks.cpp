//linked list from geeksforgeeks
#include<iostream>
using namespace std;
struct node{
	int data;
	struct node* next;
};
//function for adding the pointer in front
void push(struct node** head_ref, int data){
	struct node* new_node = new struct node;
	new_node->data = data; //there is no need of making a different case for empty list case
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
	return;
}
//function for adding the pointer at the end
void append(struct node** head_ref,int data){
	struct node* new_node = new struct node;
	struct node* temp = (*head_ref);
	new_node->data = data;
	new_node->next = NULL;
	if(*head_ref == NULL){
		*head_ref = new_node;
		return;
	}
	while((*head_ref)->next != NULL){
		(*head_ref)= (*head_ref)->next;
	}
	(*head_ref)->next = new_node;
	(*head_ref)= temp;
	return;

}
//function to print the linked list
void printlist(struct node* head){
	//struct node* temp = head;
	while(head != NULL){
		cout<<head->data<<"\t";
		head = head->next;
}
	cout<<endl;
	return;
}
//function add a node after nth node
void insert(struct node** head_ref, int num, int data){
	struct node* new_node = new struct node;
	new_node->data = data;
	struct node* temp = *head_ref;
	for(int i=1;i<num;i++){
		temp = temp->next;
	}
	new_node->next = temp->next;
	temp->next = new_node;
	return;
}
//function to delete nth node
void delete_nth_node(struct node** head_ref,int num){
	struct node* temp = *head_ref;
	struct node* prev;
	//embed a code to say if the linked list length doesnot contain that number of node
	while(num>1){
		prev = temp;
		temp = temp->next;
		num--;
}
	prev->next = temp->next;
	delete(temp);
	return;
}
//function to delete given integer from linked list
void delete_num(struct node** head_ref, int num){
	struct node* temp = *head_ref;
	struct node* prev;
	
	if(temp->data == num){
		*head_ref = temp->next;
		delete(temp);
		return;
}
	while(temp!= NULL && temp->data != num){
		prev = temp;
		temp = temp->next;
}
	if(temp == NULL){
		cout<<"linked list doesn't contain the number"<<endl;
}
	prev->next = temp->next;
	delete(temp);
	return;
}
//recursive function to get the length of the linked list
int getnode(struct node* head){
	if(head == NULL)
		return 0;
	else
		return 1+getnode(head->next);
}
//iterative function to get the length of the linked list 
int getcount(struct node* head){
	struct node* temp = head;
	int count = 0;
	while(temp != NULL){
		count++;
		temp = temp->next;
}
	return count;
}
//recursive function to search an element in linked list with return type boolean
bool search_element(struct node* head, int key){
	if(head == NULL)
		return false;
	if(head->data == key)
		return true;
	
	return search_element(head->next,key);
	
}
//iterative function to search an element in a linked list
bool search_element_iter(struct node* head, int key){
	while(head != NULL){
	if(head->data == key)
		return true;
	head = head->next;
}
	return false;
}
//recursive function to get the nth node of the linked list
int get_nth_node_rec(struct node* head, int num){
	if(num==1)
		return head->data;
		num--;
		return get_nth_node_rec(head->next,num);
}
//iterative function to get the nth node from linked list geeks for geeks
int get_nth_node_iter(struct node* head, int num){
	while(num != 1){
		head= head->next;
		num--;
}
	return head->data;
}
//if we are provided a pointer to the next node in a linked list and asked to delete it then the funtion is
// make a temp node, copy the data from the node where the pointer is pointing and delete the node
//this function does not work when the last node is to be deleted
void delete_given_pointer_node(struct node* ptr){
	struct node* temp = ptr->next;//this is very very important because the ptr wil save the data of the next node in temp
	ptr->data = temp->data;
	ptr->next = temp->next;
	delete(temp);
	
}
//function to return the nth pointer from the end
//funda: take two pointer(ref and main), move the reference till nth node from head,then move reference and main till ref reaches null
int nth_node_from_end(struct node* head,int num){
	struct node* ref = head;
	struct node* main_p = head;
	while(num != 1){
		ref = ref->next;
		if(ref == NULL)
			cout<<"the number of node you provided is greater than the length of the linked list"<<endl;// to check, error
		num--;
}
	while(ref != NULL){
		ref = ref->next;
		if(ref == NULL)
			break;
		main_p = main_p->next;
}
	return main_p->data;
}
//recursive function to print the nth node from the end of the linked list geeks for geeks
//funda: go to the end of the linked list and while returning increment if it's equal to n print the data
void printnthfromlast(struct node* head, int n){
	static int i = 0;
	if(head == NULL)
		return;
	printnthfromlast(head->next,n);
	if(++i == n)
		cout<<head->data<<endl;
}
//function to delete the linked list
void delete_linked_list(struct node** head_ref){
	struct node* temp = *head_ref;
	while(*head_ref != NULL){
		temp = *head_ref;
		*head_ref = (*head_ref)->next;
		delete(temp);
}
}
// function to print linked list in recursive function
void printlist_recursive(struct node** head_ptr){
	cout<<(*head_ptr)->data<<endl;
	if((*head_ptr)->next == NULL)
		return;
	else
		return printlist_recursive(&((*head_ptr)->next));
}
//recursive function to write linked list
void delete_linked_list_recur(struct node** head_ref){
	if(*head_ref == NULL)
		return;
	struct node* temp = *head_ref;
	delete_linked_list_recur(&((*head_ref)->next));
	delete(temp);
	(*head_ref) = NULL;	
}
void deletelist(struct node *n){
	if(n->next!=NULL){
		deletelist(n->next);
}
	cout<<"Node to be deleted: "<<n->data<<endl;
	delete(n);
}
//function that counts number of times a number appeared in linked list
int count_rep_node(struct node* head, int num){
	int count = 0;
	while(head){
		if(num == head->data)
			count++;
	head = head->next;
}
	return count;
}
//recursive function to count the number of times a node appeared in linked list
int count_rep_node_recur(struct node* head, int num){
	if(head == NULL)
		return 0;
	if(head->data == num) 
		return 1+count_rep_node_recur(head->next, num);
	else
		return count_rep_node_recur(head->next, num);
	
}
//function to delete linked list
//funda: go tto the end of the linked list then change it's output
void reverse_linked_list(struct node** head_ref){
	if(*head_ref == NULL)
		return;
	struct node* first = *head_ref;
	struct node* rest = first->next;

	if (rest == NULL)
		return;
	reverse_linked_list(&rest);
	first->next->next = first;

	first->next = NULL;

	*head_ref = rest;
}
//iterative function to reverse a linked list
// this is done by  taking three nodes as prev, current and next and interchanging between them
void reverse_linked_list_iter(struct node** head_ref){
	struct node* prev = NULL;
	struct node* current = *head_ref;
	struct node* next;

	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;// this is to pass the head pointer to the end of the linked list
}
//detecting loop in a linked list
//funda: start the linked list from two pointer, move first one twice as first as second one, if they meet then loop
int detect_loop(struct node* head){
	struct node* first = head;
	struct node* second = head;
	while(first && first->next && second){
		second = second->next;
		first = first->next->next;
		if(first == second){
			cout<<"detected loop"<<endl;
			return 1;
		}
	}
	return 0;
}
int detect_loop_util(struct node* first, struct node* second){
	if(first == second)
		return 1;
	if(second->next && second->next->next)
		return detect_loop_util(first->next, second->next->next);
	return 0;
}
//recursive function to determine loop in linked list
int detect_loop_recur(struct node* head){
	if(head->next && head->next->next)
		return detect_loop_util(head->next,head->next->next);
	else 
		return 0;
}
struct node* get_middle_node(struct node* head){
	struct node* first = head;
	struct node* second = head;
	while(first->next && first->next->next){
		first = first->next->next;
		second = second->next;
	}
	//return second->data;
	return second;
}
//function to check if the linked list is palindrome or not 
//this uses the two earlier function which are being implemented 
//break the linked list from the middle and compare the two list to each other
int check_palindrome(struct node* head){
	struct node* middle = get_middle_node(head);
	reverse_linked_list(&(middle->next));
	printlist(middle->next);
	struct node* temp = middle->next;
	while(temp != NULL){
		if(head->data != temp->data){
			cout<<"not palindrome"<<endl;
			return 0;
		}
		head = head->next;
		temp = temp->next;
	}
	reverse_linked_list(&(middle->next));
	return 1;
}
// helping function to check palindrome recursive function
int check_palindrome_recur_util(struct node ** left, struct node* right){
	if(right == NULL) //if the right reaches the NULL then return true because we dont want to mess with that
		return true;
	bool check = check_palindrome_recur_util(left,right->next);
	if(check){
		bool ret =(right->data == (*left)->data);
		(*left) = (*left)->next;
		return ret;
	}
	else
		return check;
}
//recursive function implementation of checking palindrome
int check_palindrome_recur(struct node* head){
	struct node** temp = &head;
	return check_palindrome_recur_util(temp, head); 
}
//function to swap alternate nodes from linked list 
void swap_alt_node(struct node** head_ref){
	struct node* temp;
	if(*head_ref && (*head_ref)->next){
		temp = (*head_ref)->next;
		(*head_ref)->next = (*head_ref)->next->next;
		temp->next = (*head_ref);
		swap_alt_node(&((*head_ref)->next));

	}
	else
		return;
	*head_ref = temp;
}
//iterative function insert a function in a sorted linked list
void insert_node_sorted_ll(struct node**head_ref,int data){
	struct node* new_node = new struct node;
	struct node* temp = *head_ref;
	new_node->data = data;
	if((*head_ref) == NULL || (*head_ref)->data >= data){
		new_node->next = temp;
		(*head_ref) = new_node;
		return;
	}
	while((*head_ref)->next->data < data || (*head_ref)->next == NULL){
		(*head_ref) = (*head_ref)->next;
	}
	new_node->next = (*head_ref)->next;
	(*head_ref)->next = new_node;
	(*head_ref) = temp;
	return;
}
//recursive function to insert a node to a sorted linked list
void insert_node_sorted_recur(struct node** head_ref,int num){
	struct node* new_node = new struct node;
	new_node->data = num;
	if((*head_ref) == NULL || (*head_ref)->data >= num ){
		new_node->next = (*head_ref);
		
		(*head_ref) = new_node;
		return;
	}
	if((*head_ref)->next == NULL){
		new_node->next = NULL;
		(*head_ref)->next = new_node;
		return;
	}
	return insert_node_sorted_recur(&((*head_ref)->next),num);
}
//if two linked list are intersected then:
//1) Get count of the nodes in first list, let count be c1.
//2) Get count of the nodes in second list, let count be c2.
//3) Get the difference of counts d = abs(c1 – c2)
//4) Now traverse the bigger list from the first node till d nodes so that from here onwards both the lists have equal no of nodes.
//5) Then we can traverse both the lists in parallel till we come across a common node. (Note that getting a common node is done by comparing the address of the nodes)
int get_intersect_node(struct node* head1, struct node* head2){
	int count1 = getcount(head1);
	int count2 = getcount(head2);
	int max  = (count1>= count2) ? count1:count2;
	struct node* max_head = (count1>=count2) ? head1:head2;
	struct node* min_head = (max_head == head1) ? head2:head1;
	int min = (max == count1)? count2:count1;
	while(max-min){
		max_head = max_head->next;
		max--;
	}
	while(max_head != NULL){
		if(max_head->data == min_head->data)
			return max_head->data;
		max_head= max_head->next;
		min_head = min_head->next;
	}
}
//brilliant funda to calculate the intersection point of the linked list
//1) Let X be the length of the first linked list until intersection point.
   //Let Y be the length of the second linked list until the intersection point.
   //Let Z be the length of the linked list from intersection point to End of
   //the linked list including the intersection node.
   //We Have
           //X + Z = C1;
           //Y + Z = C2;
//2) Reverse first linked list.
//3) Traverse Second linked list. Let C3 be the length of second list - 1. 
     //Now we have
        //X + Y = C3
     //We have 3 linear equations. By solving them, we get
       //X = (C1 + C3 – C2)/2;
       //Y = (C2 + C3 – C1)/2;
       //Z = (C1 + C2 – C3)/2;
      //WE GOT THE INTERSECTION POINT.
//4)  Reverse first linked list.
//applying the funda 
int get_intersect_node_method_second(struct node* head1,struct node* head2){
	int c1 = getcount(head1);
	int c2 = getcount(head2);
	reverse_linked_list(&head1);
	int c3 = getcount(head2)-1;
	int x = (c1+c3-c2)/2;
	reverse_linked_list(&head1);
	while(x){
		head1 = head1->next;
	}
	return head1->data;
}
//delete the repeating nodes from a sorted linked list
//funda:check the next node of the linked list if that is the same as prev then delete it
void delete_repeat_nodes(struct node** head_ref){
	struct node* temp = (*head_ref);
	int check = (*head_ref)->data;
	while((*head_ref)->next){
		if((*head_ref)->next->data == check){
			struct node* delete_node = (*head_ref)->next;
			(*head_ref)->next = (*head_ref)->next->next;
			delete(delete_node);
		}
		(*head_ref) = (*head_ref)->next;
		check = (*head_ref)->data;
	}
	(*head_ref) = temp;
}
void delete_repeat_nodes_util(struct node** head_ref,int num){
	if(*head_ref== NULL)
		return; //upto this correct
	if((*head_ref)->data == num){
		struct node* temp = (*head_ref);
		(*head_ref) = (*head_ref)->next;
		delete(temp);
		delete_repeat_nodes_util(head_ref,num);
	}
	else
		delete_repeat_nodes_util(&((*head_ref)->next),(*head_ref)->data);
}
//recursive function to delete the repeating nodes from the linked list
void delete_repeat_nodes_recur(struct node** head_ref){
	delete_repeat_nodes_util(&((*head_ref)->next),(*head_ref)->data);
}

//fucntion to move the last element of the linked list to the first
//funda: going to the last of the linked list returning its data 
// making a new node from that data in the head

//1. there is another funda that is provided in the geeks for geeks
//make two pointer one after another when the first one reaches the end fetch its data and from second pointer make  it's next NULL
//take the last data and make it head
//
//2. there is another funda by venki. go the the end of the LL make it circular by joining it to head and break it after the last pointer


int fetch_last_node_data(struct node** head_ref){
	struct node* temp = *head_ref;
	while(temp->next->next != NULL){
		temp = temp->next;
	}
	int num = temp->next->data;
	temp->next = NULL;
	return num;
}
void move_last_to_front(struct node** head_ref){
	struct node* new_node = new struct node;
	int num = fetch_last_node_data(head_ref);
	new_node->data = num;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
//function to delete alternate nodes from the linked list 
//iterative function to delete alternate nodes 

//function to creawte a new linked list from the intersection of two sorted linked list
struct node* intersetion_ll(struct node* head1, struct node* head2){
	struct node* result = NULL;
	struct node** result_ref = &result;
	while(head1 != NULL && head2 != NULL){
		if(head1->data == head2->data){
			//append(&result, head1->data); //we should always use push because it does not have to traverse from beginning to end 
			//
			//result_ref = &((*result_ref)->next);
			push(result_ref, head1->data);
			result_ref = &((*result_ref)->next);
			head1= head1->next;
			head2 = head2->next;
		}
		else if(head1->data < head2->data)
			head1 = head1->next;
		else
			head2 = head2->next;
	}
	return result;
}
struct node* intersetion_ll_recur(struct node* head1, struct node* head2){
	if(head1 == NULL || head2 == NULL)
		return NULL;
	if(head1->data < head2->data)
		return intersetion_ll_recur(head1->next, head2);
	if(head1->data > head2->data)
		return intersetion_ll_recur(head1,head2->next);
	struct node* temp = new struct node;
	temp->data = head2->data;

	temp->next = intersetion_ll_recur(head1->next,head2->next);
	return temp;
}

//another recursive function to make a linked list out of intersection of two sorted linked list
void sortedIntersection(struct node *head1,struct node *head2,struct node** result_ref)

{

	if(head1==NULL || head2==NULL) return;

	if(head1->data < head2->data) 
		sortedIntersection(head1->next,head2,result_ref);

	else 
		sortedIntersection(head1,head2->next,result_ref);

	if(head1->data == head2->data)

		push(result_ref,head1->data);
	return;
	

}
//utlilty function to that of upper function 
struct node* sortedIntersection_util(struct node* head1, struct node* head2){
	struct node* result = NULL;
	sortedIntersection(head1,head2,&result);
	return result;
}

//function to delete alternate nodes 
void delete_alt_nodes(struct node** head_ref){
	if(*head_ref == NULL || (*head_ref)->next == NULL)
		return;
	struct node* temp = (*head_ref)->next;
	(*head_ref)->next = (*head_ref)->next->next;
	delete(temp);
	return delete_alt_nodes(&((*head_ref)->next));
}

//quite elegant solution to check if the linked list are identical or not
bool identical(struct node *a,struct node *b)
{
	return ((a==NULL && b==NULL)||((a->data==b->data)&&identical(a->next,b->next)));
}

//recursive function to merge two sorted linked list 
struct node* merge_sorted_lists(struct node* head1, struct node* head2){
	if(!head1)
		return head2;
	else if(!head2)
		return head1;
	struct node* temp = new struct node;

	if(head1->data <= head2 ->data){
		
		temp->data = head1->data;
		temp->next = merge_sorted_lists(head1->next, head2);
	}
	else {
		temp->data = head2->data;
		temp->next = merge_sorted_lists(head1, head2->next);
	}
	return temp;
}
struct node* SortedMerge(struct node* a, struct node* b) 
{
  struct node* result = NULL;
 
  /* Base cases */
  if (a == NULL) 
     return(b);
  else if (b==NULL) 
     return(a);
 
  /* Pick either a or b, and recur */
  if (a->data <= b->data) 
  {
     result = a;
     result->next = SortedMerge(a->next, b);
  }
  else
  {
     result = b;
     result->next = SortedMerge(a, b->next);
  }
  return(result);
}

//elegant inplace algorithm for merging two linked lists 
//inplace means no extra place is required
struct node* sortedmerge(struct node *head1, struct node *head2)
{
	struct node *head,*tail;
	if(head1->data > head2->data)
	{
		head=head2;
		tail=head;
		head2=head2->next;
	}
	else
	{
		head=head1;
		tail=head;
		head1=head1->next;
	}
	while(head1!=NULL && head2!=NULL)
	{
		if(head1->data<head2->data)
		{
			tail->next=head1;
			head1=head1->next;
			tail=tail->next;
		}
		else
		{
			tail->next=head2;
			head2=head2->next;
			tail=tail->next;
		}
	}
	while(head1!=NULL)
	{
		tail->next=head1;
		head1=head1->next;
		tail=tail->next;
	}
	while(head2!=NULL)
	{
		tail->next=head2;
		head2=head2->next;
		tail=tail->next;
	}
	return head;
}

struct node* split_mid(struct node* head){
	struct node* fast = head->next;
	struct node* slow = head;
	while(fast != NULL && fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	fast = slow->next;
	slow->next = NULL;
	return fast;
}

//merge sort for llinked list 
void merge_sort(struct node** head_ref){
	if((*head_ref)->next == NULL)
		return;
	struct node* result = NULL;
	result = split_mid(*head_ref);
	merge_sort(head_ref);
	merge_sort(&result);
	*head_ref = sortedmerge(*head_ref,result);
	return;
}

//function for insertion sort for a single linked list 
void insertion_sort(struct node** head_ref){
	struct node* new_node = NULL;
	while((*head_ref) != NULL){
		insert_node_sorted_recur(&new_node,(*head_ref)->data);
		(*head_ref) = (*head_ref)->next;
	}
	(*head_ref) = new_node;
}

//function to reverse the linked list by a group of sizes 
struct node* reverse_by_groups(struct node* head,int k){
	struct node* current = head;
	struct node* prev = NULL;
	struct node* next = NULL;
	int count = 0;

	while(current != NULL && count < k){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}

	if(next != NULL){
		head->next = reverse_by_groups(next,k);
	}
	return prev;
}

//to delete nodes which have higher value on the right
//funda: reverse the list, take a max value, if next_node < max delete next_node, else next_node->data = max;
void delete_node_with_greate_right_value_util(struct node** head_ref){
	struct node* temp = *head_ref;
	int max = (*head_ref)->data;
	struct node* delete_node;
	while(*head_ref != NULL && (*head_ref)->next != NULL){
		if((*head_ref)->next->data < max){
			delete_node = (*head_ref)->next;
			(*head_ref)->next  = (*head_ref)->next->next;
			delete(delete_node);
		}
		else{
			
			(*head_ref) = (*head_ref)->next;
			max = (*head_ref)->data;
		}
	}
	(*head_ref) = temp;
}

void delete_node_with_greate_right_value(struct node** head_ref){
	reverse_linked_list(head_ref);

	delete_node_with_greate_right_value_util(head_ref);

	reverse_linked_list(head_ref);

}
//iterative function to rotate a linked list using an after num counterclockwise
void rotate_linked_list(struct node** head_ref,int k){
	struct node* temp = (*head_ref);
	struct node* head = (*head_ref);
	while(temp->next != NULL){
		k--;
		temp = temp->next;
		if(k==1)
			head = temp;
	}
	temp->next = (*head_ref);
	(*head_ref) = head->next;
	head->next = NULL;
}


//function to segregate a linked list 
// there are two funda:
//1. go the end of the linked list and while traversing again throw the odd nodes to the end of the linked list
//2. make two linked list of odd and even and then join them, the catch 
//method 1
void segregate_linked_list(struct node** head_ref){
	struct node* temp = *head_ref;
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = (*head_ref);
	(*head_ref) = (*head_ref)->next;
	temp->next->next = NULl;
}
int main(){
	struct node* head = NULL;
	struct node* head1 = NULL;
	struct node* result  = NULL;

	append(&head,10);
	append(&head,87);
	append(&head,18);
	append(&head,9);
	append(&head,56);
	append(&head,56);
	append(&head,13);
	append(&head,107);

	printlist(head);

	segregate_linked_list(&head);

	printlist(head);
	return 0;
}
