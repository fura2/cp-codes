#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;

	int sum=0;
	rep(i,n) sum+='E'-min(s[i],'E');
	printf("%.15f\n",1.0*sum/n);

	return 0;
}
