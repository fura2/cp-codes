#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int x,y; cin>>x>>y;
	cout<<(a[x]==a[y]?"Yes":"No")<<endl;
	return 0;
}
