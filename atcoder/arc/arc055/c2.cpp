#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

vector<int> Z_algorithm(const string& s){
	int n=s.length();
	vector<int> z(n);
	for(int i=1,pre=0;i<n;i++){
		if(z[pre]>(i-pre)+z[i-pre]){
			z[i]=z[i-pre];
		}
		else{
			int j=max(pre+z[pre]-i,0);
			while(i+j<n && s[j]==s[i+j]) j++;
			z[i]=j;
			pre=i;
		}
	}
	z[0]=n;
	return z;
}

int main(){
	string s; cin>>s;
	int n=s.length();

	string t=s;
	reverse(t.begin(),t.end());

	auto z1=Z_algorithm(s);
	auto z2=Z_algorithm(t);

	lint ans=0;
	rep(k,n) if(k>n-k) {
		int len_A=min(z1[k],n-k-1);
		int len_C=min(z2[n-k],n-k-1);
		if(len_A+len_C>=n-k){
			ans+=(len_A+len_C)-(n-k)+1;
		}
	}
	printf("%lld\n",ans);

	return 0;
}
