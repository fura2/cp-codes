#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

bool ispali(int a){
	string s=to_string(a);
	int n=s.length();
	rep(i,n) if(s[i]!=s[n-i-1]) return false;
	return true;
}

int main(){
	int a,b; cin>>a>>b;
	int ans=0;
	for(int i=a;i<=b;i++) if(ispali(i)) ans++;
	cout<<ans<<endl;

	return 0;
}
