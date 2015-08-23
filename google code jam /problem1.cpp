#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
string switch_str(string str){
	double num = str.length();
	if(num == 0)
		return str;
	double k=0;
	while(num){
		if(str[k] == '0')
			str[k] = '1';
		else if(str[k] == '1')
			str[k] = '0';
		k++;
		num--;
	}
	return str;
		
}
string reverse_str(string str){
	if(!str.length())
		return str;
	double i = 0;
   	double j = str.length() - 1;
 	char temp;
   while (i < j) {
      temp = str[i];
      str[i] = str[j];
      str[j] = temp;
      i++;
      j--;
   }
	return str;

}
string geenerate(string str,double i){
	if(i==0)
		return str;
	string s;
	s =str+"0";
	str = switch_str(str);
	str = reverse_str(str);
	s = s+str;
	return geenerate(s,i-1);
}
int main(){
	int n,max=0;
	float d;
	cin>>n;
	int *t = new int[n];
	for(int k=0;k<n;k++){
		cin>>t[k];
		if(t[k]>max)
			max = t[k];
	}
	d = log(max)/log(2);
	string str = "";
	double i = floor(d)+1;
	str = geenerate(str,i);
	for(int k=0;k<n;k++){
		cout<<"Case #"<<k+1<<": "<<str[t[k]-1]<<endl;
	}
	return 0;
}