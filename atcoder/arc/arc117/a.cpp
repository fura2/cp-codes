#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);

	vector<int> a(n),b(m);
	rep(i,n) a[i]=i+1;
	rep(j,m) b[j]=-(j+1);
	if     (n<m) a[n-1]+=m*(m+1)/2-n*(n+1)/2;
	else if(n>m) b[m-1]-=n*(n+1)/2-m*(m+1)/2;

	rep(i,n) printf("%d ",a[i]);
	rep(j,m) printf("%d%c",b[j],j<m-1?' ':'\n');

	return 0;
}
