#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,l[10]; cin>>n;
	rep(i,n) cin>>l[i];

	sort(l,l+n);

	cout<<(accumulate(l,l+n-1,0)>l[n-1]?"Yes":"No")<<endl;

	return 0;
}
