#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<utility>
#include<map>
using namespace std;
//sort by frequency using hash map 

int main(){
	map<int,int>my_map;
	vector<pair<int,int> >mapvector;
	int n,key,value;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>key;
		if(my_map.count(key))
			my_map[key]++;
		else
			my_map[key] = 1;
	}
	for(map<int,int>::iterator it= my_map.begin();it!= my_map.end();++it)
		mapvector.push_back(*it);
	sort(mapvector.begin(),mapvector.end());
	for(vector<int,int>::iterator it = mapvector.begin();it!= mapvector.end();++it)
		cout<<it->first<<" "<<it->second<<endl;
	return 0;
}