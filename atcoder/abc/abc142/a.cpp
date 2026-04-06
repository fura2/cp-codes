#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++) if(i%2==1) cnt++;
	printf("%.9f\n",1.0*cnt/n);

	return 0;
}
