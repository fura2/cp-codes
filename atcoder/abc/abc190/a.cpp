#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,c; cin>>a>>b>>c;
	puts((c==0&&a>b)|(c==1&&a>=b)?"Takahashi":"Aoki");
	return 0;
}
