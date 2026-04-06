#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;

	if(n%2==0) return puts("-1"),0;

	int k=n/2;
	string t="b";
	rep(i,k){
		if     (i%3==0) t="a"+t+"c";
		else if(i%3==1) t="c"+t+"a";
		else            t="b"+t+"b";
	}
	printf("%d\n",s==t?k:-1);

	return 0;
}
