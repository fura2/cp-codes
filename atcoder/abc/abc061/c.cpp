#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n;
	lint k; cin>>n>>k;
	pair<int,int> a[100000];
	rep(i,n) cin>>a[i].first>>a[i].second;

	sort(a,a+n);

	rep(i,n){
		k-=a[i].second;
		if(k<=0){
			cout<<a[i].first<<endl;
			break;
		}
	}

	return 0;
}
