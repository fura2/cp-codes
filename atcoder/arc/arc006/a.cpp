#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	vector<int> a(6),c(6);
	int b;
	rep(i,6) scanf("%d",&a[i]);
	scanf("%d",&b);
	rep(i,6) scanf("%d",&c[i]);

	int cnt=0;
	rep(i,6) if(count(a.begin(),a.end(),c[i])>0) cnt++;

	if     (cnt==6) puts("1");
	else if(cnt==5) puts(count(c.begin(),c.end(),b)>0?"2":"3");
	else if(cnt==4) puts("4");
	else if(cnt==3) puts("5");
	else puts("0");

	return 0;
}
