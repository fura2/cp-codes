#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int d; cin>>d;

	string s="Christmas";
	rep(_,25-d) s+=" Eve";
	cout<<s<<endl;

	return 0;
}
