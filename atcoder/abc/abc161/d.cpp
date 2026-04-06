#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

vector<lint> res;

void dfs(vector<int>& a){
	int n=a.size();
	if(n>10) return;

	lint num=0;
	rep(i,n) num=10*num+a[n-i-1];
	if(a[n-1]!=0) res.emplace_back(num);

	rep(d,10) if(abs(a[n-1]-d)<=1) {
		a.emplace_back(d);
		dfs(a);
		a.pop_back();
	}
}

int main(){
	rep(d,10){
		vector<int> a(1,d);
		dfs(a);
	}

	sort(res.begin(),res.end());

	int k; scanf("%d",&k);
	printf("%lld\n",res[k-1]);

	return 0;
}
