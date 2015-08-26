#include<iostream>
using namespace std;
struct node{
	char data;
	struct node* next;
};
void pushstack(struct node** stack_ref,char c){
	struct node* new_node = new struct node;
	new_node->data = c;
	if(*stack_ref == NULL){
		*stack_ref = new_node;
		new_node->next = NULL;
		return;
	}
	new_node->next = *stack_ref;
	*stack_ref = new_node;
	return;
}

char popstack(struct node** stack_ref){
	struct node* delete_node = *stack_ref;
	char c = delete_node->data;
	*stack_ref = (*stack_ref)->next;
	delete(delete_node);
	return c;
}
int main(){
	struct node* stack = NULL;
	int count = 0;
	string expression;
	cin>>expression;
	for(int i=0;i<expression.length();i++){
		cout<<expression[i]<<endl;
		if(expression[i] == '(' || expression[i] == '{' || expression[i] == '['){
			pushstack(&stack,expression[i]);
			count++;
		}
		else if(expression[i] == ')'){
			if(!('(' == popstack(&stack))){
				cout<<"not balanced"<<endl;
				return 0;
			}
			count--;
		}
		else if(expression[i] == '}'){
			if(!('{' == popstack(&stack))){
				cout<<"not balanced"<<endl;
				return 0;
			}
			count--;
		}
		else if(expression[i] == ']'){
			if(!('[' == popstack(&stack))){
				cout<<"not balanced"<<endl;
				return 0;
			}
			count--;
		}
	}
	if(!count){
		cout<<"expression is balanced"<<endl;
	}
	else
		cout<<"expression is not balanced"<<endl;
	return 0;
}