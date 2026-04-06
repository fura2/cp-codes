#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	string s; cin>>s;
	int n=s.length();

	lint ans=0;
	vector<int> a;
	rep(i,n+1){
		if     (i<n   && s[i]=='A') a.emplace_back(0);
		else if(i<n-1 && s[i]=='B' && s[i+1]=='C') a.emplace_back(1), i++;
		else{
			int cnt=0;
			rep(j,a.size()){
				if(a[j]==0) cnt++;
				else        ans+=cnt;
			}
			a.clear();
		}
	}
	printf("%lld\n",ans);

	return 0;
}
