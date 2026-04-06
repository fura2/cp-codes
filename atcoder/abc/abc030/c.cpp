#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m,x,y; scanf("%d%d%d%d",&n,&m,&x,&y);
	vector<int> a(n),b(m);
	rep(i,n) scanf("%d",&a[i]);
	rep(i,m) scanf("%d",&b[i]);

	int ans=0,t=0,i=0,j=0;
	while(1){
		i=lower_bound(a.begin()+i,a.end(),t)-a.begin();
		if(i==n) break;
		t=a[i]+x;
		j=lower_bound(b.begin()+j,b.end(),t)-b.begin();
		if(j==m) break;
		t=b[j]+y;
		ans++;
	}
	printf("%d\n",ans);

	return 0;
}
