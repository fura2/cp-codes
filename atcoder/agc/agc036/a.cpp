#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint s; scanf("%lld",&s);

	lint x1=min(s,lint(1e9));
	lint y2=(s+x1-1)/x1;
	lint x2=1;
	lint y1=x1*y2-s;

	printf("%lld %lld %lld %lld 0 0\n",x1,y1,x2,y2);

	return 0;
}
