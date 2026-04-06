#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,L; cin>>n>>L;
	int x=0,i;
	for(i=0;i<n;i++){
		int d; cin>>d;
		x+=d;
		if(x>L) break;
	}
	cout<<i+1<<endl;

	return 0;
}
