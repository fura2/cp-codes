#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int d,n; cin>>d>>n;
	cout<<(n<100?n:n+1)<<string(2*d,'0')<<endl;

	return 0;
}
