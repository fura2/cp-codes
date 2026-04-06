#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	int ans=100;
	rep(i,n){
		int a; cin>>a;
		int cnt=0;
		while(a%2==0) a/=2, cnt++;
		ans=min(ans,cnt);
	}
	cout<<ans<<endl;

	return 0;
}
