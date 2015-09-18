#include<iostream>
#include<cstring>
#include<climits>
using namespace std;

struct node{
	 int data;
	 int left;
	 int right;
	struct node* next;
};
void push(struct node** head_ref,  int data){
	struct node* new_node = new struct node;
	new_node->data = data; //there is no need of making a different case for empty list case
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
	return;
}

void swap( int** arr,  int a, int b)
{
    for( int i=0;i<=2;i++){
		 int c = arr[i][a];
		arr[i][a] = arr[i][b];
		arr[i][b] = c;
	}
}
 

int partition ( int **arr,  int l,  int h, int t)
{
	 int z = ( t == 1) ? 2 : 1;
     int x = arr[z][h];   
     int i = (l - 1);  
 
    for (int j = l; j <= h- 1; j++)
    {
        if (arr[z][j] <= x)
        {
            i++;    
            swap(arr,i,j);  
        }
    }
    swap(arr,i + 1,h);  
    return (i + 1);
}
 
void quickSort( int **arr,  int l,  int h, int t)
{
    if (l < h)
    {
         int p = partition(arr, l, h,t); 
        quickSort(arr, l, p - 1,t);
        quickSort(arr, p + 1, h,t);
    }
}

void make_s(struct node* head){
	while(head->next != NULL){
		head->left = -1;
		head = head->next;
	}
	head->left = -1;
	return;
}

 int fill(struct node* head,  int sum,   int* diff, int i,  int* result,  int* left_main){

	 int sum2 = 0;
	while(head->left != -1){
		sum2 = sum2 + head->left;
		head = head->next;
	}
	head->left = sum2+ i;
	head->right = sum - (head->left);
	*left_main = head->left;
	 int max = (head->left > head->right) ? head->left : head->right;
	 int min = (head->left < head->right) ? head->left : head->right;
	if((max - min) < *diff){
		*diff = max - min;
		*result = max;
		//cout<<head->data<<endl;
		// cout<<i<<" "<<*result<<endl;
	}
	return head->data;
}
void fill2(struct node* head, int i, int sum,  int* left_main){
	while(head->data != i && head->next){
		head = head->next;
	}
	head->left = *left_main;
	head->right = sum - head->left;

	return;
}

int main() {
	int start_s=clock();
     int n,x,y,nd;
	  int sum = 0;
	  int diff = INT_MAX;
	  int result = 0;
	  int left = 0;
	cin>>n;
	 int** arr = new  int*[3];
	for( int i=0;i<3;i++){
		arr[i] = new  int[n+1];
	}
	for( int i=1;i<=n;i++){
		arr[0][i] = i;
		cin>>arr[1][i];
		sum = sum + arr[1][i];
	}
	// cout<<sum<<endl;
	struct node** a = new struct node*[n+1];
	for( int i=0;i<n-1;i++){
		cin>>x>>y;
		arr[2][x]++;
		arr[2][y]++;
		push(&a[x],y);
		push(&a[y],x);
	}
	
	quickSort(arr,1,n,1);
	for( int i=1;i<=n;i++){
		make_s(a[i]);
	}

	// for(int i=0;i<=2;i++){
	// 	for(int j = 1;j<=n;j++){
	// 		cout<<arr[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	for( int i=1;i<n;i++){
		nd = fill(a[arr[0][i]],sum,&diff,arr[1][i],&result,&left);
		fill2(a[nd],arr[0][i],sum,&left);

	}
	cout<<result<<endl;
	
    return 0;
}
