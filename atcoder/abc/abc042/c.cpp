#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; cin>>n>>k;
	bool ng[10]={};
	rep(i,k){ int d; cin>>d; ng[d]=true; }

	while(1){
		char s[8]; sprintf(s,"%d",n);
		bool ok=true;
		for(int i=0;s[i];i++) if(ng[s[i]-'0']) ok=false;
		if(ok) break;
		n++;
	}

	printf("%d\n",n);

	return 0;
}
