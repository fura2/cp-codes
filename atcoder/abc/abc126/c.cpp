#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; cin>>n>>k;

	double ans=0;
	for(int i=1;i<=n;i++){
		int a=i;
		double p=1.0/n;
		while(a<k) a*=2, p/=2;
		ans+=p;
	}
	cout<<setprecision(9)<<ans<<endl;

	return 0;
}
