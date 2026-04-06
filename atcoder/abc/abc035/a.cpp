#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class T> T gcd(const T& a,const T& b){ return b==0?a:gcd(b,a%b); }

int main(){
	int w,h; cin>>w>>h;
	int g=gcd(w,h);
	cout<<w/g<<':'<<h/g<<'\n';
	return 0;
}
