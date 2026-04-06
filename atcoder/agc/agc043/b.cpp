#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

inline int binomial_parity(int n,int r){ return ~n&r?0:1; }

int main(){
	int n;
	string s; cin>>n>>s;

	rep(i,n) s[i]--;

	int res=0;
	rep(i,n) if(binomial_parity(n-1,i)==1) res=(res+s[i]-'0')%2;
	if(res==1) return puts("1"),0;

	if(count(s.begin(),s.end(),'1')>0) return puts("0"),0;

	replace(s.begin(),s.end(),'2','1');

	res=0;
	rep(i,n) if(binomial_parity(n-1,i)==1) res=(res+s[i]-'0')%2;
	puts(res==0?"0":"2");

	return 0;
}
