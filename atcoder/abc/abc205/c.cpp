#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint a,b,c; scanf("%lld%lld%lld",&a,&b,&c);

	if(a<0 && b<0){
		if(c%2==1){
			swap(a,b);
		}
	}
	else if(a<0){
		if(c%2==1){
			puts("<");
			return 0;
		}
	}
	else if(b<0){
		if(c%2==1){
			puts(">");
			return 0;
		}
	}
	a=abs(a);
	b=abs(b);

	puts(a<b?"<":a==b?"=":">");

	return 0;
}
