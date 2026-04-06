#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,a[100000]; cin>>n;
	map<int,int> f;
	rep(i,n){
		int a; cin>>a;
		++f[a];
	}

	vector<int> b{0,0};
	for(auto x:f) if(x.second>=2) {
		while(x.second>=2){
			b.emplace_back(x.first);
			x.second-=2;
		}
	}

	sort(b.rbegin(),b.rend());
	cout<<1LL*b[0]*b[1]<<endl;

	return 0;
}
