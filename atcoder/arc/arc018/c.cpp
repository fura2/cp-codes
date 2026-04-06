#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w; scanf("%d%d",&h,&w);
	int x0,a,p; scanf("%d%d%d",&x0,&a,&p);

	if(a%p==0){
		int x1=x0%p;
		printf("%d\n",x0<=x1?0:2*(h-1));
		return 0;
	}

	int B[1000][1000];
	B[0][0]=x0;
	rep(i,h) rep(j,w) if(i+j>0) {
		if(j>0) B[i][j]=(B[i][j-1]+a)%p;
		else    B[i][j]=(B[i-1][w-1]+a)%p;
	}

	static pair<int,pair<int,int>> S[1000000];
	rep(i,h) rep(j,w) S[i*w+j]={B[i][j],{i,j}};
	sort(S,S+h*w);

	int ans=0;
	rep(i,h){
		int X[1000];
		rep(j,w){
			auto p=S[i*w+j].second;
			ans+=abs(p.first-i);
			X[j]=p.second;
		}
		sort(X,X+w);
		rep(j,w) ans+=abs(j-X[j]);
	}
	printf("%d\n",ans);

	return 0;
}
