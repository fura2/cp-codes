#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int T,n; scanf("%d%d",&T,&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int m,idx=0; scanf("%d",&m);
	rep(i,m){
		int b; scanf("%d",&b);
		while(idx<n && a[idx]+T<b) idx++;
		if(idx==n || b<a[idx]) return puts("no"),0;
		idx++;
	}
	puts("yes");

	return 0;
}
