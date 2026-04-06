#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const char B4[4][5]={
	"abcc",
	"abdd",
	"eegh",
	"ffgh"
};

const char B5[5][6]={
	"ahhgg",
	"ai..f",
	"bi..f",
	"b.jje",
	"ccdde"
};

const char B7[7][8]={
	"a.hh.gg",
	"aii..k.",
	"..m..kf",
	"b.m...f",
	"bl.nn..",
	".l..jje",
	"cc.dd.e"
};

int main(){
	int n; scanf("%d",&n);

	if(n==2) return puts("-1"),0;

	char B[1000][1001]={};
	rep(i,n) rep(j,n) B[i][j]='.';

	if(n%3==0){
		rep(k,n/3){
			B[3*k+0][3*k+0]='a';
			B[3*k+1][3*k+0]='a';
			B[3*k+2][3*k+1]='b';
			B[3*k+2][3*k+2]='b';
		}
	}
	else{
		int dp[1001];
		rep(i,n+1) dp[i]=-1;
		dp[0]=0;
		rep(i,n-4+1) if(dp[i]!=-1) dp[i+4]=4;
		rep(i,n-5+1) if(dp[i]!=-1) dp[i+5]=5;
		rep(i,n-7+1) if(dp[i]!=-1) dp[i+7]=7;

		vector<int> P;
		{
			int now=n;
			while(now>0) P.emplace_back(dp[now]), now-=dp[now];
		}

		int pos=0;
		for(int a:P){
			rep(i,a) rep(j,a) {
				if     (a==4) B[pos+i][pos+j]=B4[i][j];
				else if(a==5) B[pos+i][pos+j]=B5[i][j];
				else if(a==7) B[pos+i][pos+j]=B7[i][j];
			}
			pos+=a;
		}
	}

	rep(i,n) puts(B[i]);

	return 0;
}
