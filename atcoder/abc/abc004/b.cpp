#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	char B[4][4];
	rep(i,4) rep(j,4) scanf(" %c",&B[i][j]);
	rep(i,4) rep(j,4) printf("%c%c",B[3-i][3-j],j<3?' ':'\n');
	return 0;
}
