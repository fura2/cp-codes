#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s;
	int k; cin>>s>>k;

	int n=s.length();
	int pre=0;
	vector<int> A;
	rep(i,n) if(i==n-1 || s[i]!=s[i+1]) {
		A.emplace_back(i-pre+1);
		pre=i+1;
	}

	if(k==1 || s[0]!=s[n-1]){
		int cnt=0;
		for(int a:A) cnt+=a/2;
		cout<<1LL*cnt*k<<endl;
	}
	else{
		int m=A.size();
		if(m==1){
			cout<<1LL*n*k/2<<endl;
		}
		else{
			int cnt=0;
			for(int i=1;i<m-1;i++) cnt+=A[i]/2;
			cout<<1LL*cnt*k+1LL*(A[0]+A[m-1])/2*(k-1)+A[0]/2+A[m-1]/2<<endl;
		}
	}

	return 0;
}
