#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b; cin>>a>>b;
	cout<<min({abs(b-a),abs(b-a+10),abs(b-a-10)})<<'\n';
	return 0;
}
