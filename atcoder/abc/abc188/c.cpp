#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(1<<n);
	rep(i,1<<n) scanf("%d",&a[i]);

	int i1=max_element(a.begin(),a.begin()+(1<<n-1))-a.begin();
	int i2=max_element(a.begin()+(1<<n-1),a.end())-a.begin();

	printf("%d\n",a[i1]<a[i2]?i1+1:i2+1);

	return 0;
}
