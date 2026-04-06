#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,d[100000]; cin>>n;
	rep(i,n) cin>>d[i];

	sort(d,d+n);

	cout<<d[n/2]-d[n/2-1]<<endl;

	return 0;
}
