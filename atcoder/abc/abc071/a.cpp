#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int x,a,b; cin>>x>>a>>b;
	cout<<(abs(x-a)<abs(x-b)?'A':'B')<<endl;
	return 0;
}
