#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int x,y; scanf("%d%d",&x,&y);
	puts(min(x,y)+3>max(x,y)?"Yes":"No");
	return 0;
}
