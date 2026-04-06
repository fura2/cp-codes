#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> p(n);
	rep(i,n) scanf("%d",&p[i]), p[i]--;

	vector<int> pos(n);
	rep(i,n) pos[p[i]]=i;

	vector<int> cnt(n);
	cnt[n-1]=1;
	for(int i=n-2;i>=0;i--){
		if(pos[i]<pos[i+1]) cnt[i]=cnt[i+1]+1;
		else                cnt[i]=1;
	}
	printf("%d\n",n-*max_element(cnt.begin(),cnt.end()));

	return 0;
}
