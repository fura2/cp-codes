#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int r,g,b; cin>>r>>g>>b;
	cout<<((2*g+b)%4==0?"YES":"NO")<<endl;
	return 0;
}
