#include<iostream>
#include<climits>
#include<string>
#include<cstring>
#include<ctime>
using namespace std;
struct node{
	int data;
	struct node* next;
};

void swap(int **arr,int a,int b){
	for(int i=0;i<=2;i++){
		int c = arr[i][a];
		arr[i][a] = arr[i][b];
		arr[i][b] = c;
	}
}
int partition(int **arr,int l,int r,int t){
	int z = ( t == 1) ? 2 : 1;
	int x = arr[z][r];
	int i = l-1;
	for(int j=l;j<r-1;j++){
		if(arr[z][j]<=x){
			i++;
			swap(arr,i,j);
		}
	}
	swap(arr,i+1,r);
	return i+1;
}
void quicksort(int **arr, int l,int r,int t){
	if(l < r){
		int p = partition(arr,l,r,t);
		quicksort(arr,l,p-1,t);
		quicksort(arr,p+1,r,t);
	}
}
void swap(int** arr, int a,int b)
{
    for(int i=0;i<=2;i++){
		int c = arr[i][a];
		arr[i][a] = arr[i][b];
		arr[i][b] = c;
	}
}
 

int partition (int arr[], int l, int h)
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
 
void quickSort(int **arr, int l, int h,int t)
{
    if (l < h)
    {
        int p = partition(arr, l, h,t); 
        quickSort(arr, l, p - 1,t);
        quickSort(arr, p + 1, h,t);
    }
}
void push(struct node** head_ref, int data){
	struct node* new_node = new struct node;
	new_node->data = data; //there is no need of making a different case for empty list case
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
	return;
}
void delete_num(struct node** head_ref, int num){
	struct node* temp = *head_ref;
	struct node* prev;
	
	if(temp->data == num){
		*head_ref = temp->next;
		delete(temp);
		return;
}
	while(temp!= NULL && temp->data != num){
		prev = temp;
		temp = temp->next;
}
	if(temp == NULL){
		cout<<"linked list doesn't contain the number"<<endl;
}
	prev->next = temp->next;
	delete(temp);
	return;
}

int main(){
	int start_s=clock();
	int n,x,y;
	long long int sum = 0;
	long long int remain = 0;
	cin>>n;
	int** arr = new int*[3];
	for(int i=0;i<3;i++){
		arr[i] = new int[n+1];
	}
	for(int i=1;i<=n;i++){
		arr[0][i] = i;
		cin>>arr[1][i];
		sum = sum + arr[1][i];
	}
	struct node** a = new struct node*[n+1];
	for(int i=0;i<n-1;i++){
		cin>>x>>y;
		arr[2][x]++;
		arr[2][y]++;
		push(&a[x],y);
		push(&a[y],x);
	}
	
	quicksort(arr,1,n,1);
	
	
	int count = 0;
	//cout<<sum<<endl;
	//cout<<a[1]->data<<endl;
	for(int i=1;i<n;i++){

		for(int j = i;j<n;j++){
			if(arr[2][j] == 1)
				count++;
			else
				break;
		}
		quickSort(arr,i,count,2);
		
		
		if(sum - arr[1][i] > remain + arr[1][i] ){
			delete_num(&a[a[arr[0][i]]->data],arr[0][i]);
			for(int j = i+1;j<n;j++){
				if(arr[0][j] == (a[arr[0][i]]->data)){
					arr[2][j] = arr[2][j] - 1;
					break;
				}
			}
			sum = sum - arr[1][i];
			remain = remain + arr[1][i];
		}
		else
			break;
		count = 0;
	}
	cout<<sum<<endl;
	int stop_s=clock();
	cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
	return 0;

}