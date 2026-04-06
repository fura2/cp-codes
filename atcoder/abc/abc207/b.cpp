#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint a,b,c,d; cin>>a>>b>>c>>d;
	if(b<c*d){
		// (a+nb) <= dnc
		// <=> n >= a/(cd-b)
		printf("%lld\n",(a+c*d-b-1)/(c*d-b));
	}
	else{
		puts("-1");
	}
	return 0;
}
