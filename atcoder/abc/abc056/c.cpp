#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int x; cin>>x;
	int t;
	for(t=0;t*(t+1)/2<x;t++);
	cout<<t<<'\n';
	return 0;
}
