#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n; cin>>n; n--;

	int len=0;
	lint k=1;
	while(1){
		len++;
		k*=26;
		if(n<k){
			string ans(len,'?');
			rep(i,len){
				ans[len-1-i]='a'+n%26;
				n/=26;
			}
			cout<<ans<<'\n';
			break;
		}
		n-=k;
	}

	return 0;
}
