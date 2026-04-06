#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

string s;
lint mod,m;

lint memo[11][20000][91];

lint dfs(int i,int sum,int dsum,bool smaller){
	if(i==s.length()){
		return sum==dsum?1:0;
	}

	if(smaller && memo[i][sum][dsum]!=-1) return memo[i][sum][dsum];

	lint res=0;
	if(smaller){
		rep(d,10){
			res+=dfs(i+1,(sum*10+d)%mod,(dsum+d)%mod,true);
		}
	}
	else{
		rep(d,s[i]-'0'+1){
			res+=dfs(i+1,(sum*10+d)%mod,(dsum+d)%mod,d<s[i]-'0');
		}
	}
	if(smaller) memo[i][sum][dsum]=res;
	return res;
}

int main(){
	cin>>mod>>m;
	s=to_string(m);

	memset(memo,-1,sizeof memo);

	lint ans;
	if(mod<2e4){
		ans=dfs(0,0,0,false);
	}
	else{
		ans=0;
		for(lint x=0;x<=m;x+=mod){
			rep(i,100) if(x+i<=m) {
				int dsum=0;
				for(lint a=x+i;a>0;a/=10) dsum+=a%10;
				if((x+i)%mod==dsum) ans++;
			}
		}
	}
	ans--;
	cout<<ans<<'\n';

	return 0;
}
