#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	int ans=0;
	for(int x=1;x<=n;x++){
		bool ok=true;
		int t=x;
		while(t>0){
			if(t%10==7) ok=false;
			t/=10;
		}
		t=x;
		while(t>0){
			if(t%8==7) ok=false;
			t/=8;
		}
		if(ok) ans++;
	}
	printf("%d\n",ans);

	return 0;
}
