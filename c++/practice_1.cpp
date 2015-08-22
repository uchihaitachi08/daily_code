#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	vector<int>math;
	vector<int>::iterator  iter_jj;
	math.push_back(10);
	math.push_back(30);
	math.push_back(20);
	math.push_back(9);
	math.pop_back();
	for(iter_jj = math.begin();iter_jj != math.end();iter_jj++){
		cout<<*iter_jj<<endl;
	}
	return 0;
}
