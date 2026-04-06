#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	vector<int> p(n);
	rep(i,n) cin>>p[i];

	rep(j,n) rep(i,j+1) {
		swap(p[i],p[j]);
		bool ok=true;
		rep(k,n-1) if(p[k]>p[k+1]) ok=false;
		if(ok){ cout<<"YES"<<endl; return 0; }
		swap(p[i],p[j]);
	}
	cout<<"NO"<<endl;

	return 0;
}
