#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	string ans;
	do{
		if(n%2!=0) n--, ans='1'+ans;
		else       ans='0'+ans;
		n/=-2;
	}while(n!=0);
	cout<<ans<<endl;

	return 0;
}
