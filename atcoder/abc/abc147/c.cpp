#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

inline int popcount(int x){
	x=((x>>1)&0x55555555)+(x&0x55555555);
	x=((x>>2)&0x33333333)+(x&0x33333333);
	x=((x>>4)+x)&0x0f0f0f0f;
	x+=(x>>8);
	x+=(x>>16);
	return x&0x3f;
}

int main(){
	int n; scanf("%d",&n);
	vector<int> t[15],f[15];
	rep(i,n){
		int m; scanf("%d",&m);
		rep(j,m){
			int x,y; scanf("%d%d",&x,&y); x--;
			if(y==1) t[i].emplace_back(x);
			else     f[i].emplace_back(x);
		}
	}

	int ans=0;
	rep(S,1<<n){
		bool ok=true;
		rep(i,n){
			if(S>>i&1){
				for(auto x:t[i]) if((S>>x&1)==0) ok=false;
				for(auto x:f[i]) if((S>>x&1)==1) ok=false;
			}
		}
		if(ok) ans=max(ans,popcount(S));
	}
	printf("%d\n",ans);

	return 0;
}
