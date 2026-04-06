#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

vector<int> p;
vector<bool> er;
void sieve(int n){
	er.assign(n+1,true);
	er[0]=er[1]=false;
	for(int i=2;i*i<=n;i++) if(er[i]) for(int j=i*i;j<=n;j+=i) er[j]=false;
	rep(i,n+1) if(er[i]) p.emplace_back(i);
}

bool f(int n,int q,int e){ // whether q^e | n!
	for(int i=2;i<=n;i++) if(i%q==0) {
		int a=i;
		do{
			a/=q;
			e--;
			if(e==0) return true;
		}while(a%q==0);
	}
	return false;
}

int main(){
	int n; cin>>n;

	sieve(n);

	int m=p.size(),ans=0;
	rep(i,m) rep(k,m) rep(j,k) if(i!=j && i!=k) {
		if(f(n,p[i],2) && f(n,p[j],4) && f(n,p[k],4)) ans++;
	}
	rep(i,m) rep(j,m) if(i!=j) {
		if(f(n,p[i],2) && f(n,p[j],24)) ans++;
		if(f(n,p[i],4) && f(n,p[j],14)) ans++;
	}
	rep(i,m){
		if(f(n,p[i],74)) ans++;
	}
	cout<<ans<<endl;

	return 0;
}
