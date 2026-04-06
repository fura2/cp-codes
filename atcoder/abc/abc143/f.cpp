#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const lint INF=1LL<<61;

int main(){
	int n; scanf("%d",&n);

	vector<int> cnt(n);
	rep(i,n){
		int a; scanf("%d",&a); a--;
		cnt[a]++;
	}

	sort(cnt.begin(),cnt.end());

	vector<int> next(n);
	next[n-1]=n;
	for(int i=n-2;i>=0;i--) next[i]=(cnt[i]<cnt[i+1]?i+1:next[i+1]);

	lint sum=0;
	rep(i,n) sum+=cnt[i];

	rep(i,n){
		lint ans=0,tmp=sum,last=0,d=1;
		int pos=n-i;
		while(pos<n && tmp>d*(cnt[pos]-last)){
			tmp-=d*(cnt[pos]-last);
			ans+=cnt[pos]-last;
			last=cnt[pos];
			d+=next[pos]-pos;
			pos=next[pos];
		}
		ans+=tmp/d;
		printf("%lld\n",ans);
		sum-=cnt[n-i-1];
	}

	return 0;
}
