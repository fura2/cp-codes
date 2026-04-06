#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n){
		scanf("%d",&a[i]);
		while(a[i]%2==0) a[i]/=2;
	}

	sort(a.begin(),a.end());
	printf("%ld\n",unique(a.begin(),a.end())-a.begin());

	return 0;
}
