#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	sort(a.begin(),a.end());
	lint sum=accumulate(a.begin(),a.end(),0LL);

	int i;
	for(i=n-2;i>=0;i--){
		sum-=a[i+1];
		if(2*sum<a[i+1]) break;
	}
	printf("%d\n",n-i-1);

	return 0;
}
