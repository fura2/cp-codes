#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> b(n);
	rep(i,n) scanf("%d",&b[i]);

	int x=0;
	rep(i,n) x^=b[i];

	if(x!=0) return puts("-1"),0;

	vector<int> a(n);
	rep(i,n-1) a[i+1]=a[i]^b[i];
	rep(i,n) printf("%d\n",a[i]);

	return 0;
}
