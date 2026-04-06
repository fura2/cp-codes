#include <cstdio>
#include <map>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	map<int,int> f;
	rep(i,n){ int a; scanf("%d",&a); ++f[a]; }

	int ans=0;
	for(auto x:f){
		if     (x.first<x.second) ans+=x.second-x.first;
		else if(x.first>x.second) ans+=x.second;
	}
	printf("%d\n",ans);

	return 0;
}
