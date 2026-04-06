#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(n),b(m);
	rep(i,n) scanf("%d",&a[i]);
	rep(i,m) scanf("%d",&b[i]);

	vector<int> c;
	c.insert(c.end(),a.begin(),a.end());
	c.insert(c.end(),b.begin(),b.end());
	sort(c.begin(),c.end());
	int k=unique(c.begin(),c.end())-c.begin();

	printf("%.9f\n",1.0*(n+m-k)/k);

	return 0;
}
