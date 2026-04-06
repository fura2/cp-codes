#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a[3];
	rep(i,3) cin>>a[i];

	sort(a,a+3);

	int ans=0;
	while(a[0]+1<a[2]) a[0]+=2, ans++;
	while(a[1]+1<a[2]) a[1]+=2, ans++;

	sort(a,a+3);

	if     (a[0]<a[1]) ans+=2;
	else if(a[0]<a[2]) ans++;

	cout<<ans<<endl;

	return 0;
}
