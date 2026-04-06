#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,c,d,e,f; cin>>a>>b>>c>>d>>e>>f;

	int ans1=100*a,ans2=0;
	rep(i,31) rep(j,31) rep(k,101) rep(l,101) {
		int water=100*(i*a+j*b);
		int sugar=k*c+l*d;
		if(sugar<=water/100*e && water+sugar<=f){
			if(ans2*(water+sugar)<ans1*sugar){
				ans1=water+sugar;
				ans2=sugar;
			}
		}
	}
	cout<<ans1<<' '<<ans2<<endl;

	return 0;
}
