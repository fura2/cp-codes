#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,a[100000];
	scanf("%d",&n);
	rep(i,n) scanf("%d",a+i);

	map<int,int> f1,f2;
	rep(i,n/2){
			f1[a[2*i  ]]++;
			f2[a[2*i+1]]++;
	}

	vector<pair<int,int>> b1,b2;
	for(auto it=f1.begin();it!=f1.end();++it) b1.emplace_back(-(it->second),it->first);
	for(auto it=f2.begin();it!=f2.end();++it) b2.emplace_back(-(it->second),it->first);
	b1.emplace_back(0,0);
	b2.emplace_back(0,0);

	sort(b1.begin(),b1.end());
	sort(b2.begin(),b2.end());

	int ans=n;
	rep(i,2) rep(j,2) if(b1[i].second!=b2[j].second) ans=min(ans,n/2+b1[i].first+n/2+b2[j].first);
	printf("%d\n",ans);

	return 0;
}
