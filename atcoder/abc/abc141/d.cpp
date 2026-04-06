#include <iostream>
#include <queue>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; cin>>n>>m;
	priority_queue<int> Q;
	rep(i,n){
		int a; cin>>a;
		Q.push(a);
	}

	rep(i,m){
		int a=Q.top(); Q.pop();
		Q.push(a/2);
	}

	long long ans=0;
	rep(i,n) ans+=Q.top(), Q.pop();
	cout<<ans<<endl;

	return 0;
}
