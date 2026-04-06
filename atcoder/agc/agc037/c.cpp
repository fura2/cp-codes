#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n),b(n);
	rep(i,n) scanf("%lld",&a[i]);
	rep(i,n) scanf("%lld",&b[i]);

	lint ans=0;
	priority_queue<pair<lint,int>> Q;
	rep(i,n) Q.emplace(b[i],i);
	while(!Q.empty()){
		int i; i=Q.top().second;
		Q.pop();

		lint b1=b[(i-1+n)%n];
		lint b2=b[(i+1)%n];
		lint k=(b[i]-max(b1,b2))/(b1+b2)+1;
		if(b[i]-k*(b1+b2)>a[i]){
			ans+=k;
			b[i]-=k*(b1+b2);
			Q.emplace(b[i],i);
		}
		else{
			if(b[i]>=a[i] && (b[i]-a[i])%(b1+b2)==0){
				ans+=(b[i]-a[i])/(b1+b2);
				b[i]=a[i];
			}
			else{
				puts("-1");
				return 0;
			}
		}
	}
	printf("%lld\n",ans);

	return 0;
}
