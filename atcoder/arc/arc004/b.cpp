#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,d[500]; cin>>n;
	rep(i,n) cin>>d[i];

	sort(d,d+n);

	int sum=accumulate(d,d+n,0);
	cout<<sum<<endl;
	cout<<max(2*d[n-1]-sum,0)<<endl;

	return 0;
}
