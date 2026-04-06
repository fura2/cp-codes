#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

inline int popcount(int x){
	x=((x>>1)&0x55555555)+(x&0x55555555);
	x=((x>>2)&0x33333333)+(x&0x33333333);
	x=((x>>4)+x)&0x0f0f0f0f;
	x+=(x>>8);
	x+=(x>>16);
	return x&0x3f;
}

int main(){
	int h,w,k; scanf("%d%d%d",&h,&w,&k);
	char B[10][1001];
	rep(i,h) scanf("%s",B[i]);

	int ans=INF;
	rep(S,1<<(h-1)){
		int m=0,id[10];
		rep(i,h){
			id[i]=m;
			if(i==h-1 || (S>>i&1)) m++;
		}

		int res=popcount(S);
		int cnt[10]={},pre=0;
		rep(j,w){
			bool ng=false;
			rep(i,h) if(B[i][j]=='1') {
				cnt[id[i]]++;
				if(cnt[id[i]]>k) ng=true;
			}
			if(ng){
				if(pre==j){ res=INF; break; }
				pre=j;
				j--;
				fill(cnt,cnt+m,0);
				res++;
			}
		}
		ans=min(ans,res);
	}
	printf("%d\n",ans);

	return 0;
}
