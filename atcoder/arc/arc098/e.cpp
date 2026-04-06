#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k,q; scanf("%d%d%d",&n,&k,&q);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);
	a.emplace_back(0);

	int ans=INT_MAX;
	rep(i,n){
		vector<int> b,tmp;
		rep(j,n+1) if(a[j]>=a[i]) {
			tmp.emplace_back(a[j]);

			if(j==n-1 || a[j+1]<a[i]){
				int width=tmp.size();
				if(width>=k){
					partial_sort(tmp.begin(),tmp.begin()+width-k+1,tmp.end());
					b.insert(b.end(),tmp.begin(),tmp.begin()+width-k+1);
				}
				tmp.clear();
			}
		}

		if(b.size()>=q){
			nth_element(b.begin(),b.begin()+q-1,b.end());
			ans=min(ans,b[q-1]-a[i]);
		}
	}
	printf("%d\n",ans);

	return 0;
}
