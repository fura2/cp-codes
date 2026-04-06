#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;
	vector<int> a(n+1);
	rep(i,n+1) cin>>a[i];

	int k=1e4;
	rep(i,n) k=min(k,abs(a[i]-a[i+1]));

	printf("%d\n",k);
	rep(t,k){
		rep(i,n+1){
			printf("%d%c",a[i]/k+(t<a[i]%k?1:0),i<n?' ':'\n');
		}
	}

	return 0;
}
