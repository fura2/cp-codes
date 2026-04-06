#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n;
	int a0,m; scanf("%lld%d%d",&n,&a0,&m);
	n--;

	vector<lint> sum(m+1);
	vector<int> p(m+1,-1);
	sum[0]=a0;
	p[a0]=0;
	int a=a0,t=0,per;
	while(1){
		if(t==n){
			printf("%d\n",sum[t]);
			return 0;
		}

		t++;
		a=lint(a)*a%m;
		sum[t]=sum[t-1]+a;

		if(p[a]==-1){
			p[a]=t;
		}
		else{
			per=t-p[a];
			break;
		}
	}

	lint ans=sum[p[a]];
	n-=p[a];
	ans+=n/per*(sum[p[a]+per]-sum[p[a]]);
	n%=per;
	ans+=sum[p[a]+n]-sum[p[a]];
	printf("%lld\n",ans);

	return 0;
}
