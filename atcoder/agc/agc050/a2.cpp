#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	rep(i,n) printf("%d %d\n",(2*i)%n+1,(2*i+1)%n+1);
	return 0;
}
