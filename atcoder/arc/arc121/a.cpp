#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> x(n),y(n);
	rep(i,n) scanf("%d%d",&x[i],&y[i]);

	vector<pair<int,int>> X(n),Y(n);
	rep(i,n){
		X[i]={x[i],i};
		Y[i]={y[i],i};
	}
	sort(X.begin(),X.end());
	sort(Y.begin(),Y.end());

	int i0,j0;
	if(X[n-1].first-X[0].first>=Y[n-1].first-Y[0].first){
		i0=X[0].second;
		j0=X[n-1].second;
	}
	else{
		i0=Y[0].second;
		j0=Y[n-1].second;
	}
	if(i0>j0) swap(i0,j0);

	int ans=0;
	rep(i,2) for(int j=n-1;j>=n-2;j--) {
		for(const auto& L:{X,Y}){
			int tmpi=L[i].second;
			int tmpj=L[j].second;
			if(tmpi>tmpj) swap(tmpi,tmpj);
			if(tie(tmpi,tmpj)!=tie(i0,j0)) ans=max(ans,L[j].first-L[i].first);
		}
	}
	printf("%d\n",ans);

	return 0;
}
