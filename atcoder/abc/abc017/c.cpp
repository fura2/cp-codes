#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);

	int total=0;
	vector<int> a(m+1);
	rep(i,n){
		int l,r,v; scanf("%d%d%d",&l,&r,&v); l--;
		a[l]+=v;
		a[r]-=v;
		total+=v;
	}

	rep(i,m) a[i+1]+=a[i];

	printf("%d\n",total-*min_element(a.begin(),a.end()-1));

	return 0;
}
