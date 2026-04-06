#include <algorithm>
#include <cstdio>
#include <queue>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m;
	pair<int,int> a[100000];
	scanf("%d%d",&n,&m);
	rep(i,n) scanf("%d%d",&a[i].first,&a[i].second);

	sort(a,a+n);

	int ans=0,idx=0;
	priority_queue<int> Q;
	rep(i,m){
		for(;idx<n&&a[idx].first<=i+1;idx++) Q.push(a[idx].second);
		if(!Q.empty()) ans+=Q.top(), Q.pop();
	}

	printf("%d\n",ans);

	return 0;
}
