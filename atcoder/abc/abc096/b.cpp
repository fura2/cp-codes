#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,c,k; cin>>a>>b>>c>>k;
	if(a<b) swap(a,b);
	if(a<c) swap(a,c);
	cout<<a*(1<<k)+b+c<<endl;

	return 0;
}
