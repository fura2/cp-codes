#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

vector<int> Z_algorithm(const vector<int>& a){
	int n=a.size();
	vector<int> z(n);
	for(int i=1,pre=0;i<n;i++){
		if(z[pre]>(i-pre)+z[i-pre]){
			z[i]=z[i-pre];
		}
		else{
			int j=max(pre+z[pre]-i,0);
			while(i+j<n && a[j]==a[i+j]) j++;
			z[i]=j;
			pre=i;
		}
	}
	z[0]=n;
	return z;
}

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d",&a[i]);
	rep(i,n) scanf("%d",&b[i]);

	vector<int> seq(3*n);
	rep(i,n-1) seq[i]=b[i]^b[i+1];
	seq[n-1]=-1;
	rep(i,2*n) seq[n+i]=a[i%n]^a[(i+1)%n];

	auto z=Z_algorithm(seq);

	rep(k,n){
		int x=a[k]^b[0];
		if(z[n+k]==n-1) printf("%d %d\n",k,x);
	}

	return 0;
}
