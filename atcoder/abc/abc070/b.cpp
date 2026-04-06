#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,c,d; cin>>a>>b>>c>>d;
	cout<<max(min(b,d)-max(a,c),0)<<endl;

	return 0;
}
