#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a[4];
	rep(i,4) scanf("%d",&a[i]);

	bool ok=false;
	rep(S,1<<4){
		int sum=0;
		rep(i,4){
			if(S>>i&1) sum+=a[i];
			else       sum-=a[i];
		}
		if(sum==0) ok=true;
	}
	puts(ok?"Yes":"No");

	return 0;
}
