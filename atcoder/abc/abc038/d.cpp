#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class T>
vector<int> longest_increasing_subsequence(const vector<T> &a){
	vector<int> lis;
	for(const auto& x:a){
		auto it=lower_bound(lis.begin(),lis.end(),x);
		if(it!=lis.end()) *it=x;
		else lis.emplace_back(x);
	}
	return lis;
}

int main(){
	int n; cin>>n;
	vector<pair<int,int>> a(n);
	rep(i,n) cin>>a[i].first>>a[i].second, a[i].second*=-1;

	sort(a.begin(),a.end());

	vector<int> b(n);
	rep(i,n) b[i]=-a[i].second;

	cout<<longest_increasing_subsequence(b).size()<<endl;

	return 0;
}
