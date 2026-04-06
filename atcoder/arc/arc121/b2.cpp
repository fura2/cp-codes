#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n; scanf("%d",&n);
	n*=2;

	vector<lint> R,G,B;
	rep(i,n){
		lint v;
		char c; scanf("%lld %c",&v,&c);
		if(c=='R') R.emplace_back(v);
		if(c=='G') G.emplace_back(v);
		if(c=='B') B.emplace_back(v);
	}
	sort(R.begin(),R.end());
	sort(G.begin(),G.end());
	sort(B.begin(),B.end());

	auto f=[](vector<lint> X,vector<lint> Y){
		lint res=INF;
		rep(i,X.size()){
			int j=lower_bound(Y.begin(),Y.end(),X[i])-Y.begin();
			if(j<Y.size()) res=min(res,abs(X[i]-Y[j]));
			if(j>0)        res=min(res,abs(X[i]-Y[j-1]));
		}
		return res;
	};

	if(R.size()%2==0 && G.size()%2==0 && B.size()%2==0){
		puts("0");
	}
	else if(R.size()%2==0){
		printf("%lld\n",min(f(G,B),f(R,G)+f(R,B)));
	}
	else if(G.size()%2==0){
		printf("%lld\n",min(f(R,B),f(G,R)+f(G,B)));
	}
	else{ // B.size()%2==0
		printf("%lld\n",min(f(R,G),f(B,R)+f(B,G)));
	}

	return 0;
}
