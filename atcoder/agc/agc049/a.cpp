#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	bool A[100][100];
	rep(u,n){
		string s; cin>>s;
		rep(v,n) A[u][v]=(s[v]=='1');
	}

	rep(k,n) rep(i,n) rep(j,n) A[i][j]|=A[i][k]&A[k][j];

	double ans=0;
	rep(u,n){
		int cnt=0;
		rep(v,n) if(v!=u && A[v][u]) cnt++;
		ans+=1.0/(cnt+1);
	}
	printf("%.15f\n",ans);

	return 0;
}
