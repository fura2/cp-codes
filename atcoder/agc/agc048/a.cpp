#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

void solve(){
	string s; cin>>s;
	int n=s.length();

	if(count(s.begin(),s.end(),'a')==n){
		puts("-1");
	}
	else if(s>"atcoder"){
		puts("0");
	}
	else{
		int i;
		for(i=0;s[i]=='a';i++);
		printf("%d\n",s[i]<='t'?i:i-1);
	}
}

int main(){
	int q; scanf("%d",&q); rep(_,q) solve();
	return 0;
}
