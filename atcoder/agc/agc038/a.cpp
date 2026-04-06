#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w,a,b; cin>>h>>w>>a>>b;

	rep(i, b ) cout<<string(a,'0')+string(w-a,'1')<<endl;
	rep(i,h-b) cout<<string(a,'1')+string(w-a,'0')<<endl;

	return 0;
}
