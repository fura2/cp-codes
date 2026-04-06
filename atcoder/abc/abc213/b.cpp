#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<pair<int,int>> a(n);
	rep(i,n) scanf("%d",&a[i].first), a[i].second=i;

	sort(a.begin(),a.end());

	printf("%d\n",a[n-2].second+1);

	return 0;
}
