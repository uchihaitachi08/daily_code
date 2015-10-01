#include<iostream>
#include<algorithm>
#include<vector>
#include<ctime>
using namespace std;
int main(){
	int start_s=clock();
	vector<int>v;
	int n,num;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num;
		v.push_back(num);
	}
	sort(v.begin(),v.end());
	int stop_s=clock();
	cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
	return 0;
}