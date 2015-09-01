#include<iostream>
using namespace std;
int dayofweek(int d, int m, int y)
{
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    return ( y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}
int main(){
	int d1,m1,y1,d2,m2,y2;
	int t,i,j,count =0;
	cin>>t;
	while(t--){
		cin>>d1>>m1>>y1>>d2>>m2>>y2;
		if(d1>13)
			{
				m1 = m1+1;
				if(m1==13)
				{
					m1=1;
					y1++;
				}
			}
		if(d2>=13)
			{
				m2=m2+1;
				if(m2==13)
				{
					m2=1;
					y2++;
				}
			}
		while(y1<=y2){
			if(dayofweek(13,m1,y1)==5)
				count++;
			m1++;
			if(m1>12)
			{
				m1=1;
				y1++;
			}
			if((y1>=y2)&&(m1>=m2))
			{
				break;
			}

		}
		cout<<count<<endl;
		count = 0;
	}
	return 0;
}