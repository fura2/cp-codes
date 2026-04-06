#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int calc(const string& s,const string& t){
	int n=find(t.begin(),t.end(),'?')-t.begin();

	int hist[128]={};
	rep(i,n) if(s[i]!=t[i]) hist[s[i]]++;

	int res=0;
	rep(i,n) if(s[i]!=t[i]) {
		res++;
		if(hist[t[i]]>0) hist[t[i]]--;
		else res++;
	}
	return res;
}

int main(){
	int n,k;
	string s; cin>>n>>k>>s;

	string t=s;
	sort(t.begin(),t.end());

	string ans(n,'?');
	rep(i,n){
		rep(j,t.size()){
			ans[i]=t[j];
			if(calc(s,ans)<=k){ t.erase(j,1); break; }
		}
	}
	cout<<ans<<'\n';

	return 0;
}
