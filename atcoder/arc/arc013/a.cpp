#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a[3],b[3];
	rep(i,3) cin>>a[i];
	rep(i,3) cin>>b[i];

	sort(b,b+3);

	int ans=0;
	do{
		int tmp=1;
		rep(i,3) tmp*=a[i]/b[i];
		ans=max(ans,tmp);
	}while(next_permutation(b,b+3));
	cout<<ans<<endl;

	return 0;
}
