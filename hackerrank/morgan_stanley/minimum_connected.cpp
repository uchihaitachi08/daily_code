#include<iostream>
#include<map>
#include<string>
#include<climits>
#include<cstring>

using namespace std;
#define loop(i,n) for(int i = 0; i < n; ++i)
struct node{
	bool visited;
	int weight;
	struct node* next;
};
void count_min(struct node**s, int n, int* min){

	loop(i,n){
		if(s[i]->weight < *min){
			*min = s[i]->weight;
		}
	}
}
bool find(struct node**s ,struct node* head, int b){
	if(head->visited)
		return 0;
	bool check = 0;
	head->visited = 1;
	struct node* temp = head->next;
	while(temp != NULL){
		if(temp->weight == b)
			return 1;
		if(find(s,s[temp->weight - 1],b)){
			check = 1;
			break;
		}
		temp = temp->next;
	}
	return check;
}
void change(struct node**s, struct node* head, int num){
	if(head->weight == num)
		return;
	head->weight = num;
	struct node* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
		change(s,s[temp->weight - 1],num);
	}
}
void push(struct node** s,int a,int b){
	if(!find(s,s[a-1],b)){
		s[a-1]->weight = s[a-1]->weight+s[b-1]->weight;
		struct node* temp = s[a-1];
		while(temp->next != NULL){
			temp  = temp ->next;
			change(s,s[temp->weight - 1],s[a-1]->weight);
		}
		
		temp->next = new struct node;
		temp->next->weight = b;
		s[b-1]->weight = s[a-1]->weight;
		temp  = s[b-1];
		while(temp->next != NULL){
			temp = temp->next;
			change(s,s[temp->weight - 1],s[a-1]->weight);
		}
		temp->next = new struct node;
		temp->next->weight = a;
	}
	return;
}
int main(){
	 // int start_s=clock();
	int a,n,b,c,min = INT_MAX;
	cin>>n>>b;
	struct node** s = new struct node*[n];
	loop(i,n){
		s[i] = new struct node;
	}
	loop(i,n){
		cin>>s[i]->weight;
	}
	loop(i,b){
		cin>>a>>c;
		push(s,a,c);
		loop(i,n){
			if(s[i]->weight < min){
				min = s[i]->weight;
			}
		}
		cout<<min<<endl;
		loop(i,n){
			s[i]->visited = 0;
		}
		min = INT_MAX;
	}
	// int stop_s=clock();
	// cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
	return 0;
}