#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);

	lint freq[200]={};
	rep(i,n){
		int a; scanf("%d",&a);
		freq[a%200]++;
	}

	lint ans=0;
	rep(i,200) ans+=freq[i]*(freq[i]-1)/2;
	printf("%lld\n",ans);

	return 0;
}
