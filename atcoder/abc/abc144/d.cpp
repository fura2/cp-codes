#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)
#define dbg(S) { int f=1; for(auto x:S) cerr<<(f?"[":", ")<<x, f=0; cerr<<"]\n"; }

using namespace std;

int main(){
	double a,b,x; cin>>a>>b>>x;
	if(x>=a*a*b/2){
		double theta=atan(2*(a*a*b-x)/(a*a*a));
		cout<<setprecision(15)<<theta*180/M_PI<<endl;
	}
	else{
		double theta=atan((a*b*b)/(2*x));
		cout<<setprecision(15)<<theta*180/M_PI<<endl;
	}
	return 0;
}
