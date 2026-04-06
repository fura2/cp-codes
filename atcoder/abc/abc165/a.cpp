#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,k; scanf("%d%d%d",&k,&a,&b);
	puts(b/k-(a-1)/k>0?"OK":"NG");
	return 0;
}
