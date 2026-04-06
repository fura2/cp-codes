#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,k; cin>>a>>b>>k;
	for(int c=min(a,b);;c--) if(a%c==0 && b%c==0) {
		k--;
		if(k==0){ cout<<c<<endl; break; }
	}

	return 0;
}
