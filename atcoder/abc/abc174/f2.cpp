// Mo's algorithm

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,q; scanf("%d%d",&n,&q);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]), a[i]--;

	vector<int> l(q),r(q);
	rep(i,q) scanf("%d%d",&l[i],&r[i]), l[i]--;

	int m=sqrt(n);
	vector<int> p(q);
	iota(p.begin(),p.end(),0);
	sort(p.begin(),p.end(),[&](int i,int j){
		return make_pair(l[i]/m,r[i])<make_pair(l[j]/m,r[j]);
	});

	int cnt=0;
	vector<int> freq(n);
	auto add=[&](int x){
		if(freq[a[x]]==0) cnt++;
		freq[a[x]]++;
	};
	auto del=[&](int x){
		freq[a[x]]--;
		if(freq[a[x]]==0) cnt--;
	};

	vector<int> ans(q);
	int xl=0,xr=0;
	for(int i:p){
		while(xl<l[i]) del(xl++);
		while(xl>l[i]) add(--xl);
		while(xr<r[i]) add(xr++);
		while(xr>r[i]) del(--xr);
		ans[i]=cnt;
	}
	rep(i,q) printf("%d\n",ans[i]);

	return 0;
}
