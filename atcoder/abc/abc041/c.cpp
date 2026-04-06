#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	pair<int,int> a[100000];
	rep(i,n) scanf("%d",&a[i].first), a[i].second=i;

	sort(a,a+n);

	rep(i,n) printf("%d\n",a[n-i-1].second+1);

	return 0;
}
