#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n;
	string s; cin>>n>>s;

	int sum[3][4001]={};
	for(int i=n-1;i>=0;i--){
		sum[0][i]=sum[0][i+1]+(s[i]=='R'?1:0);
		sum[1][i]=sum[1][i+1]+(s[i]=='G'?1:0);
		sum[2][i]=sum[2][i+1]+(s[i]=='B'?1:0);
	}

	lint ans=0;
	for(char c1:"RGB") for(char c2:"RGB") if(c1!=c2) {
		rep(i,n) if(s[i]==c1) {
			for(int j=i+1;j<n;j++) if(s[j]==c2) {
				int tmp;
				if(c1!='R' && c2!='R') tmp=sum[0][j+1];
				if(c1!='G' && c2!='G') tmp=sum[1][j+1];
				if(c1!='B' && c2!='B') tmp=sum[2][j+1];
				ans+=tmp;

				int k=2*j-i;
				if(k<n && s[k]!=c1 && s[k]!=c2) ans--;
			}
		}
	}
	printf("%lld\n",ans);

	return 0;
}
