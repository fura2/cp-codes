#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	puts(n==2||n==3||n==5||(n!=1&&n%2!=0&&n%3!=0&&n%5!=0)?"Prime":"Not Prime");
	return 0;
}
