#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;
class Minheap{
	int *arr;
	int capacity;
	int size;
public:
	Minheap(int capacity);

	void Minheapify(int );

	int parent(int i){return (i-1)/2;}
};

int main(){
	
	return 0;
}