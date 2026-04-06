#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	int a[100000];
	rep(i,n) cin>>a[i], a[i]--;

	int p=0;
	rep(i,n){
		if(p==1){ cout<<i<<endl; return 0; }
		p=a[p];
	}
	cout<<-1<<endl;

	return 0;
}
