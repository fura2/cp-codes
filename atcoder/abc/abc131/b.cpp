#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,l; cin>>n>>l;

	int sum=0;
	rep(i,n) sum+=l+i;

	int ans=1e9;
	rep(i,n){
		int tmp=sum-(l+i);
		if(abs(sum-ans)>abs(sum-tmp)) ans=tmp;
	}
	cout<<ans<<endl;

	return 0;
}
