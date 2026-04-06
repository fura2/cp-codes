#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

unsigned xor32(){
	static unsigned x=123456789,y=362436069,z=521288629,w=88675123;
	unsigned t=x^(x<<11);
	x=y; y=z; z=w;
	return w=(w^(w>>19))^(t^(t>>8));
}

int main(){
	int n,m,k; scanf("%d%d%d",&n,&m,&k);

	bool ng[11][11]={};
	rep(i,m){
		int a,b; scanf("%d%d",&a,&b);
		ng[a][b]=ng[b][a]=true;
	}

	int cnt=0,T=1e7,p[11];
	rep(_,T){
		iota(p,p+n,0);
		rep(i,k){
			int a=xor32()%n,b;
			do b=xor32()%n; while(a==b);
			swap(p[a],p[b]);
		}
		bool ok=true;
		rep(i,n) if(ng[p[i]][p[(i+1)%n]]) ok=false;
		if(ok) cnt++;
	}

	printf("%.9f\n",1.0*cnt/T);

	return 0;
}
