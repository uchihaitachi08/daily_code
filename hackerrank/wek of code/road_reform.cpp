#include<iostream>
#include<string>
#include<climits>
#include<ctime>
using namespace std;
 int mindistance(  int* dist,bool* spatset, int size){
	int min = INT_MAX;
	int min_index;
	for( int v = 0;v<size;v++){
		if(spatset[v] == false && dist[v] <= min){
			min = dist[v], min_index = v;			
		}
	}
	return min_index;
}

 int dijkstra( int **arr, int src, int dest, int size){
	 int dist[size];
	bool spatset[size];

	for( int i=0;i<size;i++){
		dist[i] = INT_MAX;
		spatset[i] = false;
	}

	dist[src]  = 0;
	for( int i=0;i<size;i++){
		 int u = mindistance(dist,spatset,size);
		spatset[u]  = true;
		for( int v = 0;v<size;v++){
			if (!spatset[v] && arr[u][v] && dist[u] != INT_MAX && dist[u]+arr[u][v] < dist[v])
				dist[v] = dist[u] + arr[u][v];
		}
	}
	return dist[dest];
}
void decr( int** arr, int src, int size, int min_distance){
	int sum = 0,add;
	for(int i=1;i<=size-1;i++){
		if(min_distance > dijkstra(arr,0,i,size)){
			add = min_distance - dijkstra(arr,0,i,size) - 1;
			if(add > 0)
			sum = sum + add;
		}
		if(min_distance > dijkstra(arr,i,size-1,size)){
			add = min_distance - dijkstra(arr,i,size-1,size) - 1;
			if(add > 0)
			sum = sum + add ;
		}
	}
	cout<<sum<<endl;
}
int main(){
	//int start_s=clock();
	 int n,m,a,b,cost;
	 int min_distance;
	cin>>n;
	 int **arr = new int*[n];//array for the graph
	for( int i=0;i<n;i++)
		arr[i] = new  int[n];

	//int **d = new int*[n];//array to store the minimum distance 
	//for(int i=0;i<n;i++)
		//d[i] = new int[n];


	for( int i= 0;i<n;i++){
		for( int j=0;j<n;j++){
			arr[i][j] = 0;
		}
	}
	cin>>m;
	while(m--){
		cin>>a>>b>>cost;
		if((arr[a-1][b-1]) > cost){
			arr[a-1][b-1] = cost;
			arr[b-1][a-1] = cost;
		}
	}
	//for(int i=0;i<n;i++){
		//for(int j=0;j<n;j++){
			//cout<<arr[i][j]<<" ";
		//}
		//cout<<endl;
	//}
	min_distance = dijkstra(arr,0,n-1,n);
	decr(arr,0,n,min_distance);
	//int stop_s=clock();
	//cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
	return 0;
}