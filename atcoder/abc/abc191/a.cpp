#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int v,t1,t2,d; scanf("%d%d%d%d",&v,&t1,&t2,&d);
	puts(d<v*t1||v*t2<d?"Yes":"No");
	return 0;
}
