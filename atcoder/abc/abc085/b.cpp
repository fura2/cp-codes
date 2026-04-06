#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,d[100]; cin>>n;
	rep(i,n) cin>>d[i];

	sort(d,d+n);
	cout<<unique(d,d+n)-d<<endl;

	return 0;
}
