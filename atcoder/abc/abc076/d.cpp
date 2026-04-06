#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,T[100]; cin>>n;
	double V[100];
	rep(i,n) cin>>T[i];
	rep(i,n) cin>>V[i];

	int t=0;
	double vl[40001],vr[40001];
	vl[0]=0;
	rep(i,n) rep(j,2*T[i]) {
		vl[t+1]=min(vl[t]+0.5,V[i]);
		t++;
	}
	vr[t]=0;
	for(int i=n-1;i>=0;i--) rep(j,2*T[i]) {
		vr[t-1]=min(vr[t]+0.5,V[i]);
		t--;
	}

	double ans=0;
	t=0;
	rep(i,n) rep(j,2*T[i]) {
		ans+=(min(vl[t],vr[t])+min(vl[t+1],vr[t+1]))/4;
		t++;
	}
	cout<<setprecision(9)<<ans<<endl;

	return 0;
}
