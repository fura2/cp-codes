#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	sort(a.begin(),a.end());

	rep(i,n) if(a[i]!=i+1) {
		puts("No");
		return 0;
	}
	puts("Yes");

	return 0;
}
