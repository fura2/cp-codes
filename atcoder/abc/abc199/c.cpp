#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,q;
	string s; cin>>n>>s>>q;

	bool flip=false;
	rep(_,q){
		int type,a,b; scanf("%d%d%d",&type,&a,&b); a--; b--;
		if(type==1){
			if(!flip) swap(s[a],s[b]);
			else      swap(s[(a+n)%(2*n)],s[(b+n)%(2*n)]);
		}
		else{
			flip^=true;
		}
	}
	if(flip) s=s.substr(n)+s.substr(0,n);
	cout<<s<<'\n';

	return 0;
}
