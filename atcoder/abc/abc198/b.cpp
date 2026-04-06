#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	rep(i,10){
		string t=string(i,'0')+s;
		string r=t;
		reverse(r.begin(),r.end());
		if(t==r){
			puts("Yes");
			return 0;
		}
	}
	puts("No");
	return 0;
}
