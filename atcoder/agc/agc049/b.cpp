#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n;
	string s,t; cin>>n>>s>>t;

	queue<int> Q;
	rep(i,n) if(s[i]=='1') Q.emplace(i);

	lint ans=0;
	rep(i,n){
		if(s[i]=='0' && t[i]=='1'){
			if(Q.empty()){
				puts("-1");
				return 0;
			}
			int x=Q.front(); Q.pop();
			s[i]='1';
			s[x]='0';
			ans+=x-i;
		}
		else if(s[i]=='1' && t[i]=='0'){
			if(i==n-1 || Q.size()==1){
				puts("-1");
				return 0;
			}
			assert(Q.front()==i); Q.pop();
			int x=Q.front(); Q.pop();
			s[i]=s[x]='0';
			ans+=x-i;
		}
		else if(s[i]=='1'){
			assert(Q.front()==i); Q.pop();
		}
	}
	printf("%lld\n",ans);

	return 0;
}
