#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int f[10],g[10];
	rep(i,10){
		scanf("%d",&f[i]);
		g[f[i]]=i;
	}

	int n,a[777]={}; scanf("%d",&n);
	rep(i,n){
		string s; cin>>s;
		for(char c:s) a[i]=10*a[i]+g[c-'0'];
	}

	sort(a,a+n);

	rep(i,n){
		string s=to_string(a[i]);
		for(char c:s) putchar(f[c-'0']+'0'); puts("");
	}

	return 0;
}
