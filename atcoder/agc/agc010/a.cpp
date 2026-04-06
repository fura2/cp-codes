#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	int cnt=0;
	rep(i,n){
		int a; scanf("%d",&a);
		if(a%2==1) cnt++;
	}
	puts(cnt%2==0?"YES":"NO");

	return 0;
}
