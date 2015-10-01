#include<iostream>
#include<vector>
#include<climits>
using namespace std;
//funda: check majority element by binary search tree
struct node{
	int element;
	int count;
	struct node* left;
	struct node* right;
};
//utility function to check majority 
void check_majority(vector<int>*v,int maj_index){
	int count = 0;
	for(int i=0;i<v->size();i++){
		
		if((*v)[i] == (*v)[maj_index])
			count++;
	}
	cout<<count<<endl;
		if(count > (v->size()/2))
			cout<<"majority element is "<<(*v)[maj_index]<<endl;
		else
			cout<<"no majority element"<<endl;

}
//function funda is about moore voting algorithm
//it says cancel the element which has been comes twice 
void voting_func(vector<int>*v){
	int maj_index = 0, count = 1;
	for(int i=1;i<v->size();i++){
		if((*v)[i] == (*v)[maj_index]){
			count++;
		}
		else{
			count--;
		}
		if(count == 0){
			maj_index = i;
			count = 1;
		}
	}
	check_majority(v,maj_index);
}

void push(struct node** head,int num, int* max, int * maj_element){
	if(*head == NULL){
		(*head) = new struct node;
		(*head)->element =num;
		(*head)->count = 1;
		if((*head)->count > *max){
			*max = (*head)->count;
			*maj_element = (*head)->element;
		}
		return; 
	}
	if((*head)->element < num)
		push(&((*head)->right),num,max,maj_element);
	else if(((*head)->element) > num)
		push(&((*head)->left),num,max,maj_element);
	else{
		(*head)->count = (*head)->count + 1;
		if((*head)->count > *max){
			*max = (*head)->count;
			*maj_element = (*head)->element;
		}

	}
	return;
}

int main(){
	// vector<int>v;
	// int n,num;
	// cin>>n;
	// for(int i=0;i<n;i++){
	// 	cin>>num;
	// 	v.push_back(num);
	// }
	// voting_func(&v);

	//another method to check the majority element
	struct node* head = NULL;
	int n,num,max = INT_MIN,maj_element = 0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num;
		push(&head,num,&max,&maj_element);
	}
	if(max > n/2)
		cout<<maj_element<<endl;
	else
		cout<<"no majority element"<<endl;
	return 0;
}