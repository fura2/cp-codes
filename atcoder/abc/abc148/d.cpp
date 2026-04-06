#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int next=1;
	rep(i,n) if(a[i]==next) next++;

	printf("%d\n",next==1?-1:n-(next-1));

	return 0;
}
