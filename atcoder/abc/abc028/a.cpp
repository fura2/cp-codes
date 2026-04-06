#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	puts(n<60?"Bad":n<90?"Good":n<100?"Great":"Perfect");
	return 0;
}
