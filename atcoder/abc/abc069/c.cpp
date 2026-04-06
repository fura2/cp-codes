#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)
#define dbg(S) { int f=1; for(auto x:S) cerr<<(f?"[":", ")<<x, f=0; cerr<<"]\n"; }

using namespace std;

int main(){
	int n; cin>>n;

	int cnt[3]={};
	rep(i,n){
		int a; cin>>a;
		if     (a%4==0) cnt[2]++;
		else if(a%2==0) cnt[1]++;
		else            cnt[0]++;
	}

	if(cnt[1]==0){
		puts(cnt[0]<=cnt[2]+1?"Yes":"No");
	}
	else{
		if(cnt[0]>cnt[2]){
			puts("No");
		}
		else{
			puts(cnt[2]>=1||cnt[1]>=2?"Yes":"No");
		}
	}

	return 0;
}
