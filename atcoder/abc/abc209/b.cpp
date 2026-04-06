#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,x; scanf("%d%d",&n,&x);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	rep(i,n) x-=a[i]-i%2;

	puts(x>=0?"Yes":"No");

	return 0;
}
