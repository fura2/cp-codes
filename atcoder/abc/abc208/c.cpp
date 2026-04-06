#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n;
	lint k; scanf("%d%lld",&n,&k);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<int> p(n);
	iota(p.begin(),p.end(),0);
	sort(p.begin(),p.end(),[&](int i,int j){
		return a[i]<a[j];
	});
	vector<int> q(n);
	rep(i,n) q[p[i]]=i;

	rep(i,n) printf("%lld\n",k/n+(q[i]<k%n?1:0));

	return 0;
}
