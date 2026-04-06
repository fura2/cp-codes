#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m,x; cin>>n>>m>>x;
	int l=0,r=0;
	rep(i,m){
		int a; cin>>a;
		if(a<x) l++; else r++;
	}
	cout<<min(l,r)<<endl;

	return 0;
}
