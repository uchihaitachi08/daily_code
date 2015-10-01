#include<iostream>
#include<map>
#include<string>
#include<climits>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
struct a{
	int num1;
	int num2;
	int num3;
};

bool acompare(a lhs, a rhs) { return lhs.num1 < rhs.num1; }
int main(){
	// int start_s=clock();
	vector<int>v;
	int n,q,num,l;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>num;
		v.push_back(num);
	}
	struct a* array = new struct a[q];

	for(int i=0;i<q;i++){
		cin>>array[i].num1>>array[i].num2;
		array[i].num3 = i;
	}
	sort(array,array+q,acompare);
	// for(int i=0;i<q;i++){
	// 	cout<<array[i].num1<<" "<<array[i].num2<<" "<<array[i].num3<<endl;
	// }
	int* arr4 = new int[q];
	// l = array[0].num1;
	int l_prev = -1;
	for(int j=0;j<q;j++){
		l = array[j].num1;
		if(l > l_prev){
			for(int i=0;i<v.size();i++){
				if(v[i] < l)
					v.erase(v.begin()+i);
			}
		}
		arr4[array[j].num3] = v[array[j].num2-1];
		l_prev = l;
		// for(int i=0;i<arr.size();i++){
		// 	cout<<arr[i]<<" ";
		// }
		// cout<<endl;
	}
	for(int i=0;i<q;i++){
		cout<<arr4[i]<<endl;
	}
	// int stop_s=clock();
	// cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
	return 0;
}