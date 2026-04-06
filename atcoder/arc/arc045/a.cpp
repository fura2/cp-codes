#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; getline(cin,s);
	for(char c:s){
		if(c=='L') putchar('<');
		if(c=='R') putchar('>');
		if(c=='A') putchar('A');
		if(c==' ') putchar(' ');
	}
	puts("");
	return 0;
}
