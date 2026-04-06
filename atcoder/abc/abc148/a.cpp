#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b; cin>>a>>b;
	set<int> S={1,2,3};
	S.erase(a);
	S.erase(b);
	cout<<*S.begin()<<'\n';
	return 0;
}
