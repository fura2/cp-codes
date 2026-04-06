#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int h,w,k,n; scanf("%d%d%d%d",&h,&w,&k,&n);

	vector<int> y(n),x(n),row(h),col(w);
	rep(i,n){
		scanf("%d%d",&y[i],&x[i]); y[i]--; x[i]--;
		row[y[i]]++;
		col[x[i]]++;
	}

	lint ans=0;
	rep(i,n){
		if(row[y[i]]+col[x[i]]==k)   ans--;
		if(row[y[i]]+col[x[i]]==k+1) ans++;
	}

	sort(row.begin(),row.end());
	sort(col.begin(),col.end());

	rep(i,h){
		auto p=equal_range(col.begin(),col.end(),k-row[i]);
		ans+=p.second-p.first;
	}

	printf("%lld\n",ans);

	return 0;
}
