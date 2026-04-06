#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

vector<int> p;
vector<bool> er;
void sieve(int n){
	er.assign(n+1,true);
	er[0]=er[1]=false;
	for(int i=2;i*i<=n;i++) if(er[i]) for(int j=i*i;j<=n;j+=i) er[j]=false;
	rep(i,n+1) if(er[i]) p.emplace_back(i);
}

int main(){
	sieve(55555);

	int n; cin>>n;
	for(int q:p) if(q%10==1 && n>0) cout<<q<<' ', n--;

	return 0;
}
