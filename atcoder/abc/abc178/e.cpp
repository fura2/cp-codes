#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> x(n),y(n);
	rep(i,n){
		int u,v; scanf("%d%d",&u,&v);
		x[i]=u+v;
		y[i]=u-v;
	}

	sort(x.begin(),x.end());
	sort(y.begin(),y.end());

	printf("%d\n",max(x[n-1]-x[0],y[n-1]-y[0]));

	return 0;
}
