#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	int t=0,x=0,y=0;
	rep(i,n){
		int t2,x2,y2; scanf("%d%d%d",&t2,&x2,&y2);
		int d=abs(x2-x)+abs(y2-y);
		if(t2-t<d || (t2-t)%2!=d%2){ cout<<"No"<<endl; return 0; }
	}
	cout<<"Yes"<<endl;

	return 0;
}
