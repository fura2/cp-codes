#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> p(n);
	rep(i,n) scanf("%d",&p[i]);

	sort(p.begin(),p.end());

	printf("%d\n",accumulate(p.begin(),p.begin()+k,0));

	return 0;
}
