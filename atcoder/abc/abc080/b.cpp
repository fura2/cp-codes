#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	int d=0,t=n;
	while(t>0) d+=t%10, t/=10;
	cout<<(n%d==0?"Yes":"No")<<endl;

	return 0;
}
