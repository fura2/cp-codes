#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int gcd(int a,int b){ return b?gcd(b,a%b):a; }

int main(){
	int n,a[100000]; cin>>n;
	rep(i,n) cin>>a[i];

	int right[100001];
	right[n]=0;
	rep(i,n) right[n-i-1]=gcd(right[n-i],a[n-i-1]);

	int left=0,ans=0;
	rep(i,n){
		ans=max(ans,gcd(left,right[i+1]));
		left=gcd(left,a[i]);
	}
	cout<<ans<<endl;

	return 0;
}
