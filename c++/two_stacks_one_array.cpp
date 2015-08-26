#include<iostream>
#include<climits>
using namespace std;
struct twostacks
{	
	int top1;
	int top2;
	int size;
	int *arr;
};

struct twostacks* createStack(int size){
	struct twostacks* stack = new struct twostacks;
	stack->arr = new int[size];
	stack->top1 = -1;
	stack->size = size;
	stack->top2 = size;
	return stack;
}
bool isfull(struct twostacks* stack){
	return (stack->top1 == (stack->top2-1));
}
void push1(struct twostacks* stack, int num){
	if(isfull(stack)){
		cout<<"the stack is full"<<endl;
		return;
	}
	stack->top1++;
	stack->arr[stack->top1] = num;
	cout<<num<<" is pushed to stack"<<endl;

}
void push2(struct twostacks* stack, int num){
	if(isfull(stack)){
		cout<<"the stack is full"<<endl;
		return;
	}
	stack->top2--;
	stack->arr[stack->top2] = num;
	cout<<num<<" is pushed to stack"<<endl;
}
int pop1(struct twostacks* stack){
	if(stack->top1 == -1){
		cout<<"the stack1 is empty"<<endl;
		return INT_MIN;
	}
	return stack->arr[stack->top1--];
}
int pop2(struct twostacks* stack){
	if(stack->top2 == stack->size){
		cout<<"the stack2 is empty"<<endl;
		return INT_MIN;
	}
	return stack->arr[stack->top2++];
}
void printstack(struct twostacks* stack){
	for(int i=0;i<stack->size;i++){
		cout<<stack->arr[i]<<"\t";
	}
	cout<<endl;
}
int main(){
	struct twostacks* stack = createStack(6);
	push1(stack,3);
	push1(stack,12);
	push1(stack,37);
	push1(stack,14);
	push2(stack,42);
	push2(stack,34);
	printstack(stack);
	push2(stack,7);
	printstack(stack);

	pop1(stack);
	printstack(stack);


	push2(stack,7);

	printstack(stack);

	push1(stack,43);
	pop2(stack);
	push1(stack,43);
	printstack(stack);

	return 0;

}