#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a;
	rep(i,n){
		int x; scanf("%d",&x);
		bool ok=false;
		rep(i,a.size()) if(a[i]>=x) { a[i]=x; ok=true; break; }
		if(!ok) a.emplace_back(x);
	}
	printf("%d\n",a.size());

	return 0;
}
