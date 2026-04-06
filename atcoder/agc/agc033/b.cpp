#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w,n,y0,x0;
	string s1,s2;
	cin>>h>>w>>n>>y0>>x0>>s1>>s2; y0--; x0--;

	bool ok=true;
	int t=0,b=h,l=0,r=w;
	for(int i=n-1;i>=0;i--){
		if(s2[i]=='U') b=min(b+1,h);
		if(s2[i]=='D') t=max(t-1,0);
		if(s2[i]=='L') r=min(r+1,w);
		if(s2[i]=='R') l=max(l-1,0);

		if(s1[i]=='U') t=min(t+1,h);
		if(s1[i]=='D') b=max(b-1,0);
		if(s1[i]=='L') l=min(l+1,w);
		if(s1[i]=='R') r=max(r-1,0);

		if(t>=b || l>=r) ok=false;
	}
	if(!(t<=y0 && y0<b && l<=x0 && x0<r)) ok=false;

	puts(ok?"YES":"NO");

	return 0;
}
