#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	sort(a.begin(),a.end());

	if(count(a.begin(),a.end(),0)==n) return puts("Yes"),0;

	if(n%3!=0 || (a[0]^a[n/3])!=a[2*n/3]) return puts("No"),0;

	if(count(a.begin()      ,a.begin()+n/3  ,a[0]    )!=n/3
	|| count(a.begin()+n/3  ,a.begin()+2*n/3,a[n/3]  )!=n/3
	|| count(a.begin()+2*n/3,a.end()        ,a[2*n/3])!=n/3) return puts("No"),0;

	puts("Yes");

	return 0;
}
