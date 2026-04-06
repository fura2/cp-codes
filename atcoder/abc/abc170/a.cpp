#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int x[5];
	rep(i,5) scanf("%d",&x[i]);
	rep(i,5) if(x[i]==0) printf("%d\n",i+1);
	return 0;
}
