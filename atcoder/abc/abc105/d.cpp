#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,MOD; scanf("%d%d",&n,&MOD);
	int a[100000];
	rep(i,n) scanf("%d",a+i);

	int sum=0;
	map<int,int> f;
	f[0]=1;
	lint ans=0;
	rep(i,n){
		sum=(sum+a[i])%MOD;
		ans+=f[sum]++;
	}
	cout<<ans<<endl;

	return 0;
}
