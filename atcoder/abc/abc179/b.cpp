#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d%d",&a[i],&b[i]);

	bool ok=false;
	rep(i,n-2) if(a[i]==b[i] && a[i+1]==b[i+1] && a[i+2]==b[i+2]) ok=true;
	puts(ok?"Yes":"No");

	return 0;
}
