#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d%d",&a[i],&b[i]);

	if(a==b){ puts("0"); return 0; }

	int pos=-1;
	rep(i,n) if(a[i]>b[i]) {
		if(pos==-1 || b[i]<b[pos]) pos=i;
	}

	lint ans=0;
	rep(i,n) ans+=a[i];
	ans-=b[pos];
	cout<<ans<<endl;

	return 0;
}
