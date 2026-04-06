#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s;
	cin>>n>>s;

	int t=0,a=0;
	bool b=false;
	rep(i,n){
		if(s[i]=='T'){
			t++;
			if(2*t>=n) { puts("T"); return 0; }
		}
		else{
			a++;
			if(2*a>=n) { puts("A"); return 0; }
		}
	}

	return 0;
}
