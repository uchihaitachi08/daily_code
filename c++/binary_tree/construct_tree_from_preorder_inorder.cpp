#include<iostream>
using namespace std;
struct node{
	char data;
	struct node* left;
	struct node* right;
};
struct node* new_node(char data){
	struct node* temp = new struct node;
	temp->data = data;
	return temp;
}
void construct_tree(struct node** head_ref, char *inorder, int li, int ri, char* preorder, int lp, int rp){
	if(li > ri || lp > rp)
		return;
	if(li == ri){
		*head_ref = new_node(preorder[lp]);
		return;
	}
	int index;
	for(int i=li;i<=ri;i++){
		if(inorder[i] == preorder[lp])
			index = i;
	}
	*head_ref = new_node(preorder[lp]);
	construct_tree(&((*head_ref)->left),inorder,li,index-1,preorder,lp+1,index+lp);
	construct_tree(&((*head_ref)->right),inorder,index+1,ri,preorder,index+1+lp,rp);
	return;
}
void postorder(struct node* head){
	if(head == NULL)
		return;
	postorder(head->left);
	postorder(head->right);
	cout<<head->data<<" ";
	return;
}
int main(){
	char inorder[] = {'D','B','E','A','F','C'};
	char preorder[] = {'A','B','D','E','C','F'};
	struct node* head = NULL;
	construct_tree(&head,inorder,0,5,preorder,0,5);
	postorder(head);
	return 0;
}
