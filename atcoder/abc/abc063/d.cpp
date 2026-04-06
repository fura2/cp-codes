#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n;
	lint a,b,h[100000]; cin>>n>>a>>b;
	rep(i,n) cin>>h[i];

	lint lo=0,hi=1e9;
	while(hi-lo>1){
		lint mi=(lo+hi)/2;
		lint cnt=0;
		rep(i,n) cnt+=(max(h[i]-b*mi,0LL)+a-b-1)/(a-b);
		if(mi>=cnt) hi=mi;
		else        lo=mi;
	}
	cout<<hi<<endl;

	return 0;
}
