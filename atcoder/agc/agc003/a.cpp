#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;

	int cnt[4]={};
	for(char c:s){
		if     (c=='N') cnt[0]++;
		else if(c=='S') cnt[1]++;
		else if(c=='E') cnt[2]++;
		else if(c=='W') cnt[3]++;
	}

	bool ok=true;
	if(cnt[0]*cnt[1]==0 && cnt[0]+cnt[1]>0) ok=false;
	if(cnt[2]*cnt[3]==0 && cnt[2]+cnt[3]>0) ok=false;
	puts(ok?"Yes":"No");

	return 0;
}
