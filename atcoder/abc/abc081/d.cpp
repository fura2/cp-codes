#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,a[50]; cin>>n;
	rep(i,n) cin>>a[i];

	int pos=0;
	rep(i,n) if(abs(a[pos])<abs(a[i])) pos=i;

	cout<<2*n-2<<endl;
	rep(i,n) if(i!=pos) cout<<pos+1<<' '<<i+1<<endl;
	if(a[pos]>=0){
		rep(i,n-1) cout<<i+1<<' '<<i+2<<endl;
	}
	else{
		rep(i,n-1) cout<<n-i<<' '<<n-i-1<<endl;
	}

	return 0;
}
