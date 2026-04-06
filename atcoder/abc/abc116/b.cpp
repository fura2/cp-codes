#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a; cin>>a;
	bool vis[100000]={};
	int m;
	for(m=1;!vis[a];m++){
		vis[a]=true;
		if(a%2==0) a=a/2;
		else       a=3*a+1;
	}
	printf("%d\n",m);

	return 0;
}
