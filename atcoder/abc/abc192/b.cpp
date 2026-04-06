#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();
	rep(i,n){
		if(i%2==0 && isupper(s[i])
		|| i%2==1 && islower(s[i])) return puts("No"),0;
	}
	puts("Yes");
	return 0;
}
