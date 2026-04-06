#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s,t; cin>>s>>t;
	int m=s.length(),n=t.length();

	vector<int> na1(m+1),nb1(m+1);
	vector<int> na2(n+1),nb2(n+1);
	rep(i,m){
		na1[i+1]+=na1[i]+(s[i]=='A');
		nb1[i+1]+=nb1[i]+(s[i]=='B');
	}
	rep(i,n){
		na2[i+1]+=na2[i]+(t[i]=='A');
		nb2[i+1]+=nb2[i]+(t[i]=='B');
	}

	int q; scanf("%d",&q);
	rep(_,q){
		int a,b,c,d; scanf("%d%d%d%d",&a,&b,&c,&d); a--; c--;
		int dif1=(na1[b]-na1[a])-(nb1[b]-nb1[a]);
		int dif2=(na2[d]-na2[c])-(nb2[d]-nb2[c]);
		puts((dif1-dif2)%3==0?"YES":"NO");
	}

	return 0;
}
