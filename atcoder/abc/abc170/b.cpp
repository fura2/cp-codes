#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int x,y; scanf("%d%d",&x,&y);
	rep(i,x+1) if(2*i+4*(x-i)==y) return puts("Yes"),0;
	puts("No");
	return 0;
}
