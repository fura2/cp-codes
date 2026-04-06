#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	set<int> A;
	rep(i,n){ int a; scanf("%d",&a); A.emplace(a); }
	puts(A.size()==n?"YES":"NO");

	return 0;
}
