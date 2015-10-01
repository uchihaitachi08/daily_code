#include<iostream>
#include<map>
#include<string>
#include<climits>
#include<cstring>
#include<vector>
using namespace std;
#define loop(i,n) for(int i = 0; i < n; ++i)
struct node{
	bool visited;
	int weight;
	vector<int> v;
};
bool find(struct node** s,struct node* head,int b){
	if(head->visited)
		return 0;
	bool check = 0;
	head->visited = 1;
	loop(i,head->v.size()){
		if(head->v[i] == b)
			return 1;
		if(find(s,s[head->v[i]-1],b)){
			check = 1;
			break;
		}
	}
	return check;
}
void change(struct node**s, int a, int num){
	if(s[a]->weight == num)
		return;
	s[a]->weight = num;
	loop(i,(s[a]->v).size()){
		change(s,(s[a]->v)[i]-1,num);
	}
}
void push(struct node**s, int a, int b){
	if(!find(s,s[a-1],b)){
		s[a-1]->weight = s[a-1]->weight+s[b-1]->weight;
		loop(i,(s[a-1]->v).size()){
			change(s,(s[a-1]->v)[i] - 1,s[a-1]->weight);
		}
		s[a-1]->v.push_back(b);
		s[b-1]->weight = s[a-1]->weight;
		loop(i,(s[b-1]->v).size()){
			change(s,(s[b-1]->v)[i] - 1,s[a-1]->weight);
		}
		s[b-1]->v.push_back(a);
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
		// loop(i,n)
		// 	cout<<s[i]->weight<<" ";
		// cout<<endl;
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