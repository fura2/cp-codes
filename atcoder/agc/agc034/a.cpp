#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

string s;

bool check(int l,int r){
	for(int i=l;i<r;i++) if(s[i]=='#' && s[i+1]=='#') return false;
	return true;
}

bool check2(int l,int r){
	for(int i=l;i<=r;i++) if(s[i-1]=='.' && s[i]=='.' && s[i+1]=='.') return true;
	return false;
}

int main(){
	int n,a,b,c,d; cin>>n>>a>>b>>c>>d>>s;
	a--; b--; c--; d--;

	if(c<d) puts(check(a,c)&&check(b,d)?"Yes":"No");
	else    puts(check(a,c)&&check(b,d)&&check2(b,d)?"Yes":"No");

	return 0;
}
