#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	int p[100000];
	rep(i,n) cin>>p[i], p[i]--;

	int cnt=0;
	rep(i,n-1) if(p[i]==i) {
		swap(p[i],p[i+1]);
		cnt++;
	}
	if(p[n-1]==n-1) cnt++;
	cout<<cnt<<endl;

	return 0;
}
