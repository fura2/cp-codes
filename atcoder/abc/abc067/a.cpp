#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b; cin>>a>>b;
	cout<<(a%3==0||b%3==0||(a+b)%3==0?"Possible":"Impossible")<<endl;

	return 0;
}
