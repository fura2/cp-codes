#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	bool ok=true;
	rep(i,n){
		int a; scanf("%d",&a);
		if(a%2==1 || a%3==0 || a%5==0);
		else ok=false;
	}
	puts(ok?"APPROVED":"DENIED");
	return 0;
}
