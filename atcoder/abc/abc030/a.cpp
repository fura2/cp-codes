#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,c,d; cin>>a>>b>>c>>d;
	puts(b*c>a*d?"TAKAHASHI":b*c==a*d?"DRAW":"AOKI");
	return 0;
}
