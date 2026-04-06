#include <iostream>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k,q; cin>>n>>k>>q;

	int cnt[100000]={};
	rep(i,q){
		int a; cin>>a; a--;
		cnt[a]++;
	}

	rep(i,n) cout<<(k-q+cnt[i]>0?"Yes":"No")<<endl;

	return 0;
}
