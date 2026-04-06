#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,d; scanf("%d%d",&a,&d);
	printf("%d\n",a<=d?(a+1)*d:a*(d+1));
	return 0;
}
