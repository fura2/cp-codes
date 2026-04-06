#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,k;
	string s; cin>>n>>k>>s;

	lint BASE[]={123456789,918273645};
	lint MOD=1000000007;

	vector<lint> pw[2];
	rep(i,2){
		pw[i].assign(26,1);
		rep(c,25) pw[i][c+1]=pw[i][c]*BASE[i]%MOD;
	}

	vector<lint> hash[2];
	rep(i,2){
		hash[i].resize(n);
		lint h=0;
		vector<int> hist(26);
		rep(j,n){
			int c=s[j]-'a';
			h+=pw[i][c];
			hist[c]++;
			if(j>=k){
				c=s[j-k]-'a';
				h-=pw[i][c];
				hist[c]--;
			}
			h%=MOD; if(h<0) h+=MOD;
			hash[i][j]=h;
		}
	}

	set<pair<lint,lint>> S;
	rep(j,n){
		if(j>=k){
			S.emplace(hash[0][j-k],hash[1][j-k]);
		}
		if(S.count({hash[0][j],hash[1][j]})==1){
			cout<<"YES\n";
			return 0;
		}
	}
	cout<<"NO\n";

	return 0;
}
