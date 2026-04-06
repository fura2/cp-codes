#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b; scanf("%d%d",&a,&b);
	puts(abs(a)==abs(b)?"Draw":abs(a)<abs(b)?"Ant":"Bug");
	return 0;
}
