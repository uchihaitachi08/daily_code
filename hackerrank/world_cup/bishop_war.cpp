#include<iostream>
#include<climits>
#include<string>
#include<cstring>
#include<ctime>
using namespace std;
#define hash '#'
#define dot '.'
#define star '*'

long int count(char** arr,int n,int i,int m){

	int flag1=0,flag2=0;
	long  int result = 0;
	char temp[10][10] = {0,0};
	if(i+1 !=n){
		for(int x=i;x<n;x++){
		for(int y=0;y<m;y++){
			temp[x][y] = arr[x][y];
		}
		}
	}
	
	for(int j=0;j<m;j++){
		if(arr[i][j]== dot ){
			if((i+1) != n)
			{
				int bishopj = j;
				int bishopi = i;
				for(int z=i,k = j,x = j;z<n;z++,k--,x++){
					if(arr[z][k] == star)
						flag1 = 1;

					if(flag1==0 && k>-1)
						arr[z][k] = hash;

					if(arr[z][x] == star)
						flag2 = 1;

					if(flag2==0 && x<m)
						arr[z][x] = hash;
				}
				flag1=0;
				flag2=0;
				

				result = result  + count(arr,n,bishopi+1,m);
			 
			i = bishopi;
			j = bishopj;
			for(int z=i,k = j,x = j;z<n;z++,k--,x++){
					if(k>-1)
						arr[z][k] = temp[z][k];

					if(x<m)
						arr[z][x] = temp[z][x];
				}
			
		}
		else
				result = result+1;
	}
		
	}
	
	return result;
}

int main()
{
	//int start_s=clock();
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
	//int stop_s=clock();
	//cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
	return 0;
}

