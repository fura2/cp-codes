#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,r;
	string s; cin>>n>>r>>s;

	int ans=0,p=-1;
	for(int i=n-1;i>=0;i--) if(s[i]=='.') {
		if(p==-1) p=i;
		ans++;
		i-=r-1;
	}
	ans+=max(p-r+1,0);
	printf("%d\n",ans);

	return 0;
}
