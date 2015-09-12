#include<iostream>
#include<string>
#include<cstring>
#include<ctime>
using namespace std;
char temp[10][10];
//char arr[10][10];
//void printarray(char** arr, int n, int m){
	//for(int j=0;j<n;j++){
		//for(int k = 0;k<m;k++){
			//cout<<arr[j][k]<<" ";
		//}
		//cout<<endl;
	//}
//}
long int count(char** arr,int n,int i,int m){
	long int result = 0;
	//char** temp = new char*[n];
	//for(int k = 0;k<n;k++){
		//temp[k] = new char[m];
	//}
	int num = i;
	for(int x=i;x<n;x++){
		for(int y=0;y<m;y++){
			temp[x][y] = arr[x][y];
		}
	}
	for(int j=0;j<m;j++){
		if(arr[i][j] != '*' && arr[i][j] != '#'){
			int bishopj = j;
			int bishopi = i;
			arr[i][j] == '#';
			while(i<n && j<m){
				if(arr[i][j] == '*')
					break;
				arr[i][j] = '#';
				i++;
				j++;
			}
			i = bishopi;
			j = bishopj;
			while(i < n && j > -1){
				if(arr[i][j] == '*')
					break;
				arr[i][j] = '#';
				i++;
				j--;
			}
			//printarray(arr,n,m);
			if((bishopi+1) != n)
				result = result  + count(arr,n,bishopi+1,m);
			else
				result = result+1;
			 for(int x=num;x<n;x++){
			 	for(int y = 0;y<m;y++){
			 		arr[x][y] = temp[x][y];
			 	}
			 }
			
			j = bishopj;
			i = bishopi;
		}
	}
	//for(int x = 0 ; x < n ; ++x)
	//{
//    	
    	//delete[] temp[x];
	//}
	//delete[] temp;
	return result;
}

int main()
{
	int start_s=clock();
	int n,m;
	cin>>n>>m;
	//char arr[10][10];
	char **arr = new char*[n];
	for(int i=0;i<n;i++){
		arr[i] = new char[m];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	long int result = count(arr,n,0,m);
	cout<<result<<endl;
	//int stop_s=clock();
	//cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
	return 0;
}
