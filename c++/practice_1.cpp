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
}
int main(){
	struct Stack* stack = createstack(5);
	return 0;
}
