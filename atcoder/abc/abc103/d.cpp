#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int m; scanf("%*d%d",&m);
	pair<int,int> I[100000];
	rep(i,m) scanf("%d%d",&I[i].second,&I[i].first), I[i].first--;

	sort(I,I+m);

	int ans=0,pos=-1;
	rep(i,m) if(pos<I[i].second) pos=I[i].first, ans++;
	printf("%d\n",ans);

	return 0;
}
