#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n;
string s;
vector<int> a;

bool check(int k,bool f=false){
	vector b(k,vector(n+1,0));
	rep(i,n+1) rep(j,k) b[j][i]=a[i]/k+(j<a[i]%k?1:0);

	bool ok=true;
	rep(j,k){
		rep(i,n){
			if(s[i]=='<'){
				if(b[j][i]>=b[j][i+1]) ok=false;
			}
			else{ // '>'
				if(b[j][i]<=b[j][i+1]) ok=false;
			}
		}
	}

	if(f){
		printf("%d\n",k);
		rep(j,k){
			rep(i,n+1) printf("%d%c",b[j][i],i<n?' ':'\n');
		}
	}
	return ok;
}

int main(){
	cin>>n>>s;
	a.resize(n+1);
	rep(i,n+1) cin>>a[i];

	int lo=1,hi=1e4+1;
	while(hi-lo>1){
		int mi=(lo+hi)/2;
		if(check(mi)) lo=mi;
		else          hi=mi;
	}
	check(lo,true);

	return 0;
}
