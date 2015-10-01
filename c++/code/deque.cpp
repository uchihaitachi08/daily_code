#include <iostream>
#include <deque> 
#include<climits>
using namespace std;
int main() {
    int n,N,K,num;
    int flag,index;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>N>>K;
        deque<int> mydeque;
        int curr_max = INT_MIN;
        index = -1;
        flag = 0;
        for(int j = 0;j<N;j++){
            cin>>num;
           
            // cout<<"ha"<<endl;
            mydeque.push_back(num);
            // cout<<mydeque.size()<<endl;
            if(mydeque.size() == K){
                if(flag){
                	index--;
                     if(num> curr_max && index != -1){
                        curr_max = num;
                        index = K-1;
                     }
                        
                }
                   
                if(index == -1){
                	curr_max = INT_MIN;
                    // cout<<"hello"<<endl;
                    for(int k=0;k<K;k++){
                        if(mydeque[k] > curr_max){
                            curr_max = mydeque[k];
                            index = k;
                            flag  = 1;
                            // cout<<mydeque[i]<<" ";
                        }
                    }
                }
            	
                cout<<curr_max<<" ";
                mydeque.pop_front();
            }
            
        }
        cout<<endl;
    }
    return 0;
}