#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n; cin>>n;
	int a[100][3];
	rep(i,n){
		rep(j,3) cin>>a[i][j];
		sort(a[i],a[i]+3);
	}

	int ans=INF;
	rep(i,n) rep(j,3) rep(k,i+1) rep(l,3) {
		int x=a[i][j],y=a[k][l],z=0;
		rep(t,n){
			int b[3],tmp=INF;
			rep(s,3) b[s]=a[t][s];
			do{
				if(b[0]<=x && b[1]<=y) tmp=min(tmp,b[2]);
			}while(next_permutation(b,b+3));
			z=max(z,tmp);
		}
		if(z<INF) ans=min(ans,x*y*z);
	}
	cout<<ans<<endl;

	return 0;
}
