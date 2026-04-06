#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int sum=accumulate(a.begin(),a.end(),0);
	int cnt=0;
	rep(i,n) if(a[i]*4*m>=sum) cnt++;
	puts(cnt>=m?"Yes":"No");

	return 0;
}
