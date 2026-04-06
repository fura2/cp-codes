#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

using namespace std;

ll modpow(ll a,ll n,ll m){
	ll r=1;
	for(ll x=a%m;n;n>>=1,x=(x*x)%m) if(n&1) r=(r*x)%m;
	return r;
}

const int P_MAX=100000;

vector<int> P;
void sieve(){
	static bool er[P_MAX+1];
	rep(i,P_MAX+1) er[i]=(i>=2);
	for(int i=2;i*i<=P_MAX;i++) if(er[i]) for(int j=i*i;j<=P_MAX;j+=i) er[j]=false;
	rep(i,P_MAX+1) if(er[i]) P.push_back(i);
}

int main(){
	sieve();

	int n,T;
	ll MOD; cin>>n>>T>>MOD;

	vector<int> cnt(T+1);
	rep(i,n){
		int x,y; cin>>x>>y;
		if(x<0) x=-x;
		if(y<0) y=-y;

		if(x+y>T || (x+y)%2!=T%2){
			cout<<0<<endl;
			return 0;
		}

		// the answer is (T choose x+m)*(T choose m) by Vandermonde's identity
		int m=(T-(x+y))/2;
		cnt[T]++;   cnt[T-(x+m)]--;
		cnt[x+m]--; cnt[0]++;
		cnt[T]++;   cnt[T-m]--;
		cnt[m]--;   cnt[0]++;
	}

	for(int a=T;a>0;a--) cnt[a-1]+=cnt[a];

	ll ans=1;
	for(int p:P){
		int c=0;
		for(int a=p;a<=T;a+=p){
			int tmp=a;
			do{
				c+=cnt[a];
				tmp/=p;
			}while(tmp%p==0);
		}
		ans=ans*modpow(p,c,MOD)%MOD;
	}
	cout<<ans<<endl;

	return 0;
}
