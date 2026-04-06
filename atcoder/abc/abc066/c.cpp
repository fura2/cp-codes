#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	deque<int> Q;
	rep(i,n){
		int a; cin>>a;
		if(i%2==0) Q.emplace_back(a);
		else       Q.emplace_front(a);
	}

	if(n%2==0){
		rep(i,n) cout<<Q[i]<<endl;
	}
	else{
		rep(i,n) cout<<Q[n-i-1]<<endl;
	}

	return 0;
}
