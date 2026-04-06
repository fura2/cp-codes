#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d",&a[i]);
	rep(i,n) scanf("%d",&b[i]);

	int l=0,r=1000;
	rep(i,n){
		l=max(l,a[i]);
		r=min(r,b[i]);
	}
	printf("%d\n",max(r-l+1,0));

	return 0;
}
