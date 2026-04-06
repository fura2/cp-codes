#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

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
	int n;
	string s; cin>>n>>s;

	int ans=0;
	rep(i,n){
		auto z=Z_algorithm(s.substr(i));
		rep(j,n-i) ans=max(ans,min(z[j],j));
	}
	printf("%d\n",ans);

	return 0;
}
