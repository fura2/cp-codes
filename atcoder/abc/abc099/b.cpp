#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b; cin>>a>>b;
	int sum=0;
	rep(i,b-a) sum+=i+1;
	cout<<sum-b<<endl;

	return 0;
}
