#include <cstdio>
#include <set>
#include <vector>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	static int a[1<<18];
	rep(i,1<<n) scanf("%d",a+i);

	multiset<int> S(a,a+(1<<n)),T;
	{
		auto it=--S.end();
		T.emplace(*it);
		S.erase(it);
	}
	rep(i,n){
		vector<int> tmp;
		for(int v:T){
			auto it=S.lower_bound(v);
			if(it==S.begin()){
				puts("No");
				return 0;
			}
			--it;
			tmp.emplace_back(*it);
			S.erase(it);
		}
		T.insert(tmp.begin(),tmp.end());
	}
	puts("Yes");

	return 0;
}
