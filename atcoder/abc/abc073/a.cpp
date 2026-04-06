#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	cout<<(n%10==9||n/10==9?"Yes":"No")<<endl;
	return 0;
}
