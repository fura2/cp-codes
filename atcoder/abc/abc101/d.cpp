#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int l[]={1,0,0,1,2,3,4,5,6,7,8,9,9,10};
	int r[]={9,9,19,29,39,49,59,69,79,89,99,99,109,119};
	vector<lint> ans;
	rep(i,14) for(int j=l[i];j<r[i];j++) {
		ans.emplace_back(stoll(to_string(j)+string(i,'9')));
	}

	int k; cin>>k;
	rep(i,k) cout<<ans[i]<<endl;

	return 0;
}

// experiment
/*
int f(lint n){
	int res=0;
	while(n>0){
		res+=n%10;
		n/=10;
	}
	return res;
}

int main(){
	lint n=1e7;
	vector<long double> r(n);
	for(int i=1;i<n;i++){
		lint a=i*10000000000LL+9999999999LL;
		r[i]=(long double)f(a)/a;
	}

	double mx=0;
	for(int i=n-1;i>0;i--) if(r[i]>=mx) {
		mx=r[i];
		printf("%10d,9999999999\t%.14Lf\n",i,r[i]);
	}

	return 0;
}
*/
