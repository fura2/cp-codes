#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint x; cin>>x;
	for(lint a=-1000;a<=1000;a++)  for(lint b=-1000;b<=1000;b++) if(a*a*a*a*a-b*b*b*b*b==x) {
		printf("%lld %lld\n",a,b);
		return 0;
	}
	return 0;
}
