#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int l,r; cin>>l>>r;

	if(r-l>=2019) cout<<0<<endl;
	else{
		int ans=2019;
		for(int i=l;i<=r;i++) for(int j=i+1;j<=r;j++) ans=min(ans,(int)((long long)i*j%2019));
		cout<<ans<<endl;
	}

	return 0;
}
