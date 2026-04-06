#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,x;
	string s;cin>>n>>x>>s;

	for(char c:s){
		if(c=='o') x++;
		else       x=max(x-1,0);
	}
	printf("%d\n",x);

	return 0;
}
