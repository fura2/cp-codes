#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	pair<int,int> a[100],b[100];
	rep(i,n) cin>>a[i].first>>a[i].second;
	rep(i,n) cin>>b[i].first>>b[i].second;

	sort(a,a+n,[](auto x,auto y){ return x.first>y.first; });
	sort(b,b+n,[](auto x,auto y){ return x.second<y.second; });

	int ans=0;
	bool used[100]={};
	rep(i,n){
		rep(j,n) if(!used[j] && a[i].first<b[j].first && a[i].second<b[j].second) {
			used[j]=true;
			ans++;
			break;
		}
	}
	cout<<ans<<endl;

	return 0;
}
