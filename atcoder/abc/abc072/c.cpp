#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	int hist[100002]={};
	rep(i,n){
		int a; cin>>a; a++;
		hist[a]++;
	}

	int ans=0;
	for(int a=1;a<=100000;a++){
		ans=max(ans,hist[a]+hist[a-1]+hist[a+1]);
	}
	cout<<ans<<endl;

	return 0;
}
