#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
int main(){
	//struct node* head = NULL;
	int t,N,M,v = 1;
	float result,count =0;
	//append(&head,-1);
	cin>>t;
	for(int k=0;k<t;k++){
		cin>>N>>M;
		float *o = new float[M];
		int *D = new int[N];
		int **Q = new int*[M];
		for(int i=0;i<M;i++){
			Q[i] = new int[2];
		}
		for(int i=0;i<N;i++){
			cin>>D[i];
		}
		for(int i=0;i<M;i++){
			cin>>Q[i][0]>>Q[i][1];
		}
		for(int i=0;i<M;i++){
			for(int j=Q[i][0];j<=Q[i][1];j++){
				v = v*D[j];
				count++;
			}
			result = pow(v,(1/count));
			o[i] = result;
			//append(&head,result);
			count = 0;
			v = 1;
		}
		//append(&head,-1);
		for(int i = 0;i<M;i++){
			cout<<o[i]<<endl;
		}
	}
	//printlist(head);
	return 0;
}