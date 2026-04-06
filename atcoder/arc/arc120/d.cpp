#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(2*n);
	rep(i,2*n) scanf("%lld",&a[i]);

	vector<int> p(2*n);
	iota(p.begin(),p.end(),0);
	sort(p.begin(),p.end(),[&](int i,int j){
		return a[i]<a[j];
	});

	vector<int> b(2*n);
	rep(i,2*n) b[p[i]]=(i<n?0:1);

	string ans(2*n,'?');
	stack<int> S;
	rep(i,2*n){
		if(!S.empty() && b[S.top()]!=b[i]){
			int j=S.top();
			S.pop();
			ans[j]='(';
			ans[i]=')';
		}
		else{
			S.emplace(i);
		}
	}
	cout<<ans<<'\n';

	return 0;
}
