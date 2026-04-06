#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	char c; cin>>c;
	if     (c=='A') cout<<'T'<<endl;
	else if(c=='T') cout<<'A'<<endl;
	else if(c=='C') cout<<'G'<<endl;
	else            cout<<'C'<<endl;
	return 0;
}
