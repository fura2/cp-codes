#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int m =*min_element(a.begin(),a.end());
	int m2=*max_element(a.begin(),a.end());

	if(m2-m>=2){
		puts("No");
	}
	else if(m2-m==0){
		if(m==n-1 || m<=n/2) puts("Yes");
		else                 puts("No");
	}
	else{
		int c1=count(a.begin(),a.end(),m);
		int c2=n-c1;
		if(1<=m-c1+1 && m-c1+1<=c2/2) puts("Yes");
		else                          puts("No");
	}

	return 0;
}
