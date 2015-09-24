#include<iostream>
#include<climits>
using namespace std;
int minDistance(int dist[], bool sptSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;
 
   for (int v = 0; v < n; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
 
   return min_index;
}
 
// A utility function to print the constructed distance array
int printSolution(int dist[], int n)
{
   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < V; i++)
      printf("%d \t\t %d\n", i, dist[i]);
}
 
// Funtion that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int ***graph, int src,int dest,int n)
{
     int dist[n];     // The output array.  dist[i] will hold the shortest
                      // distance from src to i
     int max = INT_MAX;
 
     bool sptSet[n]; // sptSet[i] will true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized
 
     // Initialize all distances as INFINITE and stpSet[] as false
     
 
     // Find shortest path for all vertices
     for(int j=1;j<=24;j++){
	     	for (int i = 0; i <n ; i++)
	        dist[i] = INT_MAX, sptSet[i] = false;
	 
		     // Distance of source vertex from itself is always 0
		     dist[src-1] = 0;
	     for (int count = 0; count < n; count++)
	     {
	       // Pick the minimum distance vertex from the set of vertices not
	       // yet processed. u is always equal to src in first iteration.
	       int u = minDistance(dist, sptSet);
	 
	       // Mark the picked vertex as processed
	       sptSet[u] = true;
	 
	       // Update dist value of the adjacent vertices of the picked vertex.
	       for (int v = 0; v < n; v++)
	 
	         // Update dist[v] only if is not in sptSet, there is an edge from 
	         // u to v, and total weight of path from src to  v through u is 
	         // smaller than current value of dist[v]
	         if (!sptSet[v] && graph[u+1][v+1][j] && dist[u] != INT_MAX 
	                                       && dist[u]+graph[u+1][v+1][j] < dist[v])
	            dist[v] = dist[u] + graph[u+1][v+1][j];
	     }
	     if(max > dist[dest-1])
	     	max = dist[dest-1];
 	}
 
     // print the constructed distance array
     printSolution(dist, V);
}
int main(){
	int n,m,k,a,b;
	cin>>n>>m>>k;
	int ***arr = new int**[n+1];
	for(int i=0;i<=n;i++){
		arr[i] = new int*[n+1];
		for(int j=0;j<=n;j++){
			arr[i][j] = new int[25];
		}
	}
	for(int i=0;i<m;i++){
		cin>>a>>b;
		for(int j=1;j<=24;j++){
			cin>>arr[a][b][j];
			arr[b][a][j] = arr[a][b][j];
		}
	}
	dijkstra(arr,src,dest,n);
	return 0;
}