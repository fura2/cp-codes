#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint x; cin>>x;
	lint a=100;
	for(int i=0;;i++){
		if(a>=x){
			printf("%d\n",i);
			break;
		}
		a*=1.01;
	}
	return 0;
}
