#include<iostream>
#include<vector>
// #include<algorithm>
using namespace std;
vector<int>twoSum(vector<int>& nums, int target) {
        vector<int>index;
        vector<int>num2;
        num2 = nums;
        sort(num2.begin(),num2.end());
        int ind = 0;
        for(int i=0;i<num2.size();i++){
            if(num2[i] > target){
                ind = i;
                break;
            }
        }
        for(int i=0;i<ind;i++){
            if(binary_search(num2.begin()+i+1,num2.begin()+ind,target-num2[i])){
                for(int j=0;j<nums.size();j++){
                    if(nums[j] == num2[i])
                    index.push_back(j);
                    else if(nums[j] == target-num2[i])
                    index.push_back(j);
                    if(index.size() == 2)
                    return index;
                }
            }
        }
    }
int main(){
	vector<int>myindex;
	myindex.push_back(3);
	myindex.push_back(2);
	myindex.push_back(4);
	// myindex.push_back(11);
	vector<int>new_index = twoSum(myindex,6);
	for(int i=0;i<new_index.size();i++){
		cout<<new_index[i]<<endl;
	}
	return 0;
}