#include<iostream>
#include<climits>
#include<string>
#include<cstring>
using namespace std;
void check(int* pos, char** arr, int n,int i){
	for(int k = 0;k<n;k++){
		if(arr[i][k] != '*' && arr[i][k] != '#')
			*(pos+k) = 1;
	}
}
void change_array(char** arr, int z, int i, int n, int m){
	int row = i;
	int column = z;
	arr[i][z] = '#';
	while(i<n && z<m){
				if(arr[i][z] == '*')
					break;
				arr[i][z] = '#';
				i++;
				z++;
			}
			i = row;
			z = column;
	while(i < n && z > -1){
				if(arr[i][z] == '*')
					break;
				arr[i][z] = '#';
				i++;
				z--;
			}
}
long int count(char** arr,int n,int i,int m){
	if(i>=n)
		return 1;
	long int result = 0;
	char** temp = new char*[n];
	for(int k = 0;k<n;k++){
		temp[k] = new char[m];
	}

	for(int x=i;x<n;x++){
		for(int y=0;y<m;y++){
			temp[x][y] = arr[x][y];
		}
	}
	int* pos = new int[n];
	check(pos,arr,n,i);
	for(int z = 0;z<n;z++){
		if(pos[z] == 1){
			change_array(arr,z,i,n,m);
			result = result + count(arr,n,i+1,m);
			cout<<i<<" "<<z<<" "<<result<<endl;
			for(int x=i;x<n;x++){
			 	for(int y = 0;y<m;y++){
			 		arr[x][y] = temp[x][y];
			 	}
			}
		}
	}
	for(int x = 0 ; x < n ; ++x)
	{
    	delete[] temp[x];
	}
	delete[] temp;
	return result;
}

int main()
{
	int start_s=clock();
	int n,m;
	cin>>n>>m;
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
	int stop_s=clock();
	cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
	return 0;
}