#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	lint ans=0,cum=0;
	map<lint,int> freq;
	freq[0]=1;
	rep(i,n){
		cum+=(i%2==0?1:-1)*a[i];
		ans+=freq[cum];
		freq[cum]++;
	}
	printf("%lld\n",ans);

	return 0;
}
