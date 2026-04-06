#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	multiset<int> L,R(a.begin(),a.end());
	L.insert(0);
	R.insert(0);
	rep(i,n){
		R.erase(R.find(a[i]));
		printf("%d\n",max(*L.rbegin(),*R.rbegin()));
		L.emplace(a[i]);
	}

	return 0;
}
