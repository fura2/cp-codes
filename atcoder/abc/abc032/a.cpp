#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class T> T gcd(const T& a,const T& b){ return b==0?a:gcd(b,a%b); }
template<class T> T lcm(const T& a,const T& b){ return a/gcd(a,b)*b; }

int main(){
	int a,b,n; scanf("%d%d%d",&a,&b,&n);

	int l=lcm(a,b);
	printf("%d\n",(n+l-1)/l*l);

	return 0;
}
