#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int x; cin>>x;

	int ans=1;
	for(int b=2;b*b<=x;b++){
		int a=b*b;
		while(a<=x) ans=max(ans,a), a*=b;
	}
	cout<<ans<<endl;

	return 0;
}
