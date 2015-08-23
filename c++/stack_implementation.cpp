#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//creating stack using array
struct Stack{
	int top;
	unsigned capacity;
	int *arr;
};
struct Stack* createstack(int capacity){
	struct Stack* stack = new struct Stack;
	stack->top = -1;
	stack->capacity = capacity;
	stack->arr = new int[capacity];
	return stack;
}
bool isempty(struct Stack* stack){
	return (stack->top == -1);
}
bool isfull(struct Stack* stack){
	return (stack->top == (stack->capacity  - 1));
}

void push(struct Stack* stack,int data){
	if(isfull(stack)){
		cout<<"sorry the stack is full"<<endl;
		return;
	}
	stack->arr[++stack->top] = data;
	cout<<data<<" is pushed to stack"<<endl;
}
int pop(struct Stack* stack){
	if(isempty(stack)){
		cout<<"sorry the stack is empty"<<endl;
		return;
	}
	return stack->arr[stack->top--];
}
void peek(struct Stack* stack){
	if(isempty(stack)){
		cout<<"sorry the stack is empty"<<endl;
		return;
	}
	return stack->arr[stack->top];
}
int main(){
	struct Stack* stack = createstack(5);

	push(stack, 10);

	push(stack, 10);
	push(stack, 10);
	return 0;
}
