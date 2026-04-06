#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int a,b,w; scanf("%d%d%d",&a,&b,&w);
	w*=1000;

	int mn=INF,mx=-1;
	for(int i=1;i<=w;i++){
		if(i*a<=w && w<=i*b){
			mn=min(mn,i);
			mx=max(mx,i);
		}
	}
	if(mx!=-1){
		printf("%d %d\n",mn,mx);
	}
	else{
		puts("UNSATISFIABLE");
	}

	return 0;
}
