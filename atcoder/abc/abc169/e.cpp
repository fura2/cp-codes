#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d%d",&a[i],&b[i]);

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	if(n%2==1) printf("%d\n",b[n/2]-a[n/2]+1);
	else       printf("%d\n",b[n/2]+b[n/2-1]-a[n/2]-a[n/2-1]+1);

	return 0;
}
