#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int r,d;
	long long x; cin>>r>>d>>x;
	rep(i,10){
		x=r*x-d;
		cout<<x<<endl;
	}

	return 0;
}
