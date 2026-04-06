#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n; scanf("%lld",&n);

	lint three=1;
	for(int a=1;three<n;a++){
		three*=3;

		lint five=1;
		for(int b=1;five<n;b++){
			five*=5;

			if(three+five==n){
				printf("%d %d\n",a,b);
				return 0;
			}
		}
	}
	puts("-1");

	return 0;
}
