#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b; cin>>a>>b;
	if(a<0) a++;
	if(b<0) b++;
	cout<<b-a<<endl;

	return 0;
}
