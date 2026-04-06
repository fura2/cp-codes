#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a[5];
	rep(i,5) scanf("%d",&a[i]);

	vector<int> b;
	rep(i,5) rep(j,i) rep(k,j) b.emplace_back(a[i]+a[j]+a[k]);
	sort(b.rbegin(),b.rend());

	printf("%d\n",b[2]);

	return 0;
}
