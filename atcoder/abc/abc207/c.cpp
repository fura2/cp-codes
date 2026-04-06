#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<double> l(n),r(n);
	rep(i,n){
		int type; scanf("%d%lf%lf",&type,&l[i],&r[i]);
		if     (type==2) r[i]-=0.1;
		else if(type==3) l[i]+=0.1;
		else if(type==4) l[i]+=0.1, r[i]-=0.1;
	}

	int ans=0;
	rep(i,n) for(int j=i+1;j<n;j++) if(l[i]<=r[j] && l[j]<=r[i]) ans++;
	printf("%d\n",ans);

	return 0;
}
