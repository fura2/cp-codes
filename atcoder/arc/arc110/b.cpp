#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n;
	string s; cin>>n>>s;

	if(s=="1"){
		puts("20000000000");
		return 0;
	}

	bool ok=true;
	for(int i=0;i<n;i+=3){
		if(s[i]!='1' || (i+1<n && s[i+1]!='1') || (i+2<n && s[i+2]!='0')) ok=false;
	}
	if(ok){
		printf("%lld\n",10000000000LL-(n+2)/3+1);
		return 0;
	}

	if(s[0]=='0'){
		ok=true;
		for(int i=1;i<n;i+=3){
			if(s[i]!='1' || (i+1<n && s[i+1]!='1') || (i+2<n && s[i+2]!='0')) ok=false;
		}
		if(ok){
			printf("%lld\n",10000000000LL-((n+1)/3+1)+1);
			return 0;
		}
	}

	if(n>=2 && s[0]=='1' && s[1]=='0'){
		ok=true;
		for(int i=2;i<n;i+=3){
			if(s[i]!='1' || (i+1<n && s[i+1]!='1') || (i+2<n && s[i+2]!='0')) ok=false;
		}
		if(ok){
			printf("%lld\n",10000000000LL-(n/3+1)+1);
			return 0;
		}
	}

	puts("0");

	return 0;
}
