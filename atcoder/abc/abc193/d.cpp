#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int f(string s){
	int cnt[10]={};
	rep(i,5) cnt[s[i]-'0']++;

	int res=0;
	for(int a=1;a<10;a++) res+=a*pow(10,cnt[a]);
	return res;
}

int main(){
	int k;
	string s,t; cin>>k>>s>>t;

	int cnt[10]={};
	rep(i,4){
		cnt[s[i]-'0']++;
		cnt[t[i]-'0']++;
	}

	double ans=0;
	for(int a=1;a<10;a++) if(cnt[a]+1<=k) {
		cnt[a]++;
		for(int b=1;b<10;b++) if(cnt[b]+1<=k) {
			cnt[b]++;

			s[4]='0'+a;
			t[4]='0'+b;
			if(f(s)>f(t)){
				double p;
				if(a==b) p=1.0*(k-cnt[a]+2)*(k-cnt[a]+1);
				else     p=1.0*(k-cnt[a]+1)*(k-cnt[b]+1);
				p/=1.0*(9*k-8)*(9*k-9);
				ans+=p;
			}

			cnt[b]--;
		}
		cnt[a]--;
	}
	printf("%.9f\n",ans);

	return 0;
}
