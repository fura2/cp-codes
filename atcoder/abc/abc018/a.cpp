#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,c; scanf("%d%d%d",&a,&b,&c);

	vector<int> v={a,b,c};
	sort(v.begin(),v.end());

	printf("%ld\n%ld\n%ld\n",
		3-(lower_bound(v.begin(),v.end(),a)-v.begin()),
		3-(lower_bound(v.begin(),v.end(),b)-v.begin()),
		3-(lower_bound(v.begin(),v.end(),c)-v.begin()));

	return 0;
}
