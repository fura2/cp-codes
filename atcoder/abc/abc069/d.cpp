#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w,n,a[10000];
	cin>>h>>w>>n;

	vector<int> v;
	rep(c,n){ int a; cin>>a; rep(_,a) v.emplace_back(c); }

	int B[100][100];
	rep(i,h) rep(j,w) B[i][i%2==0?j:w-j-1]=v[i*w+j];
	rep(i,h) rep(j,w) cout<<B[i][j]+1<<(j<w-1?' ':'\n');

	return 0;
}
