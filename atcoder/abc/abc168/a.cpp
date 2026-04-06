#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	char s[3][4]={"hon","pon","bon"};
	int f[]={1,1,0,2,0,0,1,0,1,0};
	int n; scanf("%d",&n);
	puts(s[f[n%10]]);
	return 0;
}
