#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint I,O,T,J,L,S,Z;
	cin>>I>>O>>T>>J>>L>>S>>Z;

	lint tmp1=I/2*2+J/2*2+L/2*2;
	lint tmp2=0;
	if(I>0 && J>0 && L>0){
		I--; J--; L--;
		tmp2=I/2*2+J/2*2+L/2*2+3;
	}
	cout<<max(tmp1,tmp2)+O<<'\n';

	return 0;
}
