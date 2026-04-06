#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class T>
vector<T> longest_increasing_subsequence(const vector<T> &a){
	vector<T> lis;
	for(const auto& x:a){
		auto it=lower_bound(lis.begin(),lis.end(),x);
		if(it!=lis.end()) *it=x;
		else lis.emplace_back(x);
	}
	return lis;
}

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	printf("%lu\n",n-longest_increasing_subsequence(a).size());

	return 0;
}
