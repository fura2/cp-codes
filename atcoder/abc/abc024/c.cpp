#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m,q; scanf("%d%d%d",&n,&m,&q);
	vector<int> l(m),r(m);
	rep(i,m) scanf("%d%d",&l[i],&r[i]), l[i]--, r[i]--;

	rep(_,q){
		int s,t; scanf("%d%d",&s,&t); s--; t--;
		int x=s,ans=-1;
		if(s<t){
			rep(i,m) if(l[i]<=x) {
				 x=max(x,r[i]);
				 if(t<=x){ ans=i+1; break; }
			}
		}
		else{
			rep(i,m) if(x<=r[i]) {
				 x=min(x,l[i]);
				 if(x<=t){ ans=i+1; break; }
			}
		}
		printf("%d\n",ans);
	}

	return 0;
}
