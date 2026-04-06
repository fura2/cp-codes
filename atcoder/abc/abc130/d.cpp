#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n;
	lint k; cin>>n>>k;
	vector<int> a(n);
	rep(i,n) cin>>a[i];

	int r=0;
	lint res=0,sum=0;
	rep(l,n){
		while(r<n && sum<k) sum+=a[r], r++;
		if(sum>=k) res+=n-r+1;
		sum-=a[l];
	}
	cout<<res<<endl;

	return 0;
}
