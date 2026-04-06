#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint r,b,x,y; cin>>r>>b>>x>>y;

	lint lo=0,hi=r+b+1;
	while(hi-lo>1){
		lint mi=(lo+hi)/2;
		bool ok=(r>=mi&&b>=mi);
		if(ok && (r-mi)/(x-1)+(b-mi)/(y-1)>=mi) lo=mi;
		else                                    hi=mi;
	}
	cout<<lo<<endl;

	return 0;
}
