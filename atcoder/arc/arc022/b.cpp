#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]), a[i]--;

	int ans=0;
	vector<int> cnt(1e5);
	for(int l=0,r=0;l<n;){
		while(r<n && cnt[a[r]]==0){
			cnt[a[r]]++;
			r++;
		}
		ans=max(ans,r-l);
		cnt[a[l]]--;
		l++;
	}
	printf("%d\n",ans);

	return 0;
}
