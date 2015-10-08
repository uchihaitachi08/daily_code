#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
bool mycompare(int i,int j){
	string string1 = to_string(i).append(to_string(j));
	string string2 = to_string(j).append(to_string(i));

	return string1.compare(string2) > 0 ? 1 : 0;
}
int main(){
	int n,num;
	cin>>n;
	vector<int>v;
	for(int i=0;i<n;i++){
		cin>>num;
		v.push_back(num);
	}
	sort(v.begin(),v.end(),mycompare);
	for(int i=0;i<n;i++){
		cout<<v[i];
	}
	cout<<endl;
}