#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,t; scanf("%d%d",&n,&t);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int cnt=0,mn=a[0],h=0;
	rep(i,n){
		mn=min(mn,a[i]);
		if(h<a[i]-mn){
			h=a[i]-mn;
			cnt=1;
		}
		else if(h==a[i]-mn){
			cnt++;
		}
	}
	cout<<cnt<<endl;

	return 0;
}
