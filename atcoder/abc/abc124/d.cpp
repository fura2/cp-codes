#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k;
	string s; cin>>n>>k>>s;

	vector<int> B,W;
	if(s[ 0 ]=='0') B.emplace_back(0);
	int pre=0;
	rep(i,n){
		if(i==n-1 || s[i]!=s[i+1]){
			if(s[pre]=='1') B.emplace_back(i-pre+1);
			else            W.emplace_back(i-pre+1);
			pre=i+1;
		}
	}
	if(s[n-1]=='0') B.emplace_back(0);

	if(k>=W.size()){ cout<<n<<endl; return 0; }

	int ans=0,sum=0;
	rep(i,k) sum+=B[i]+W[i];
	for(int i=k;i<=W.size();i++){
		sum+=B[i];
		ans=max(ans,sum);
		if(i<W.size()){
			sum-=B[i-k];
			sum+=W[i];
			sum-=W[i-k];
		}
	}
	cout<<ans<<endl;

	return 0;
}
