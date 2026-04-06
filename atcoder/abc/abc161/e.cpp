#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n,k,c;
	string s; cin>>n>>k>>c>>s;

	auto solve=[&](){
		vector<int> res;
		int pre=-INF;
		rep(i,n) if(s[i]=='o' && pre+c<i) {
			res.emplace_back(i);
			pre=i;
		}
		return res;
	};

	vector<int> L=solve();
	if(L.size()>k) return 0;

	reverse(s.begin(),s.end());

	vector<int> R=solve();
	rep(i,R.size()) R[i]=n-R[i]-1;
	reverse(R.begin(),R.end());

	rep(i,L.size()) if(L[i]==R[i]) printf("%d\n",L[i]+1);

	return 0;
}
