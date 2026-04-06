#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
	int vx=x2-x1,vy=y2-y1;
	int x3=x2-vy,y3=y2+vx;
	int x4=x3-vx,y4=y3-vy;
	cout<<x3<<' '<<y3<<' '<<x4<<' '<<y4<<endl;

	return 0;
}
