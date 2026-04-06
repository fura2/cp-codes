#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	string s; cin>>s;
	s=">"+s+"<";
	int n=s.length();

	vector<int> pos;
	rep(i,n-1) if(s[i]=='>' && s[i+1]=='<') pos.emplace_back(i+1);

	vector<int> a(n+1);
	for(int p:pos){
		for(int i=p-1;i>=0;i--){
			if(s[i]=='<') break;
			a[i]=max(a[i],a[i+1]+1);
		}
		for(int i=p;i<n;i++){
			if(s[i]=='>') break;
			a[i+1]=max(a[i+1],a[i]+1);
		}
	}

	lint ans=0;
	for(int i=1;i<n;i++) ans+=a[i];
	cout<<ans<<endl;

	return 0;
}
