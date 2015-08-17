#include <iostream> 
using namespace std;
int check_small(int num1,int num2){
	if(num1 >= num2)
		return num2;
	else
		return num1;
}
int check_factor(int num1,int num2){
	int big,factor = 1;
	int small = check_small(num1,num2);
	if(num1 == small)
		big = num2;
	else
		big = num1;
	for(int i=1;i<=small;i++){
		if((big % i) == 0 && (small % i == 0))
			factor = i;
	}
	return factor;

}
int main()
{
    int num_input,i,j,num;
    cin>>num_input;
    int **arr = new int*[num_input];
    for(i=0;i< num_input;i++){
    	arr[i] = new int[4];
    }

    for(i=0;i<num_input;i++){
    	for(j=0;j<4;j++){
    		cin>>arr[i][j];
    	}
    }
    for(i = 0;i<num_input;i++){
    	num = check_factor(arr[i][0],arr[i][1]);
    	cout<<num<<endl;
    }
    return 0;
}