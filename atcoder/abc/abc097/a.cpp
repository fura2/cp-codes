#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,c,d; cin>>a>>b>>c>>d;
	cout<<(abs(a-c)<=d||(abs(a-b)<=d&&abs(b-c)<=d)?"Yes":"No")<<endl;

	return 0;
}
