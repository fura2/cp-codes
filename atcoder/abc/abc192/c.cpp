#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

lint f(lint x){
	string s=to_string(x);
	string t1=s,t2=s;
	sort(t1.begin(),t1.end());
	sort(t2.rbegin(),t2.rend());
	return stoi(t2)-stoi(t1);
}

int main(){
	int a0,n; scanf("%d%d",&a0,&n);

	vector<lint> a(n+1);
	a[0]=a0;
	rep(i,n) a[i+1]=f(a[i]);
	printf("%lld\n",a[n]);

	return 0;
}
