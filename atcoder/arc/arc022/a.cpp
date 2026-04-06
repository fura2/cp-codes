#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int t=0;
	for(char c:s){
		if     (toupper(c)=='I' && t==0) t++;
		else if(toupper(c)=='C' && t==1) t++;
		else if(toupper(c)=='T' && t==2) t++;
	}
	puts(t==3?"YES":"NO");
	return 0;
}
