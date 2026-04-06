#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	multiset<int> S;
	rep(i,n){
		int a; scanf("%d",&a);
		auto it=S.lower_bound(a);
		if(it!=S.begin()) S.erase(--it);
		S.emplace(a);
	}

	printf("%d\n",S.size());

	return 0;
}
