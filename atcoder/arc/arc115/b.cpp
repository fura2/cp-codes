#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector C(n,vector(n,0));
	rep(i,n) rep(j,n) scanf("%d",&C[i][j]);

	vector<int> r(n),c(n);
	rep(j,n) c[j]=C[0][j];
	for(int i=1;i<n;i++) r[i]=C[i][0]-C[0][0];

	int mn=-*min_element(r.begin(),r.end());
	int mx= *min_element(c.begin(),c.end());
	if(mn>mx){
		puts("No");
		return 0;
	}

	vector<int> A(n),B(n);
	rep(i,n) A[i]=mn+r[i];
	rep(j,n) B[j]=c[j]-mn;
	rep(i,n) rep(j,n) if(C[i][j]!=A[i]+B[j]) {
		puts("No");
		return 0;
	}

	puts("Yes");
	rep(i,n) printf("%d%c",A[i],i<n-1?' ':'\n');
	rep(j,n) printf("%d%c",B[j],j<n-1?' ':'\n');

	return 0;
}
