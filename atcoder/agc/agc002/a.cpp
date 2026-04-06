#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b; cin>>a>>b;
	if(a<=0 && 0<=b) cout<<"Zero"<<endl;
	else if(a>0 || (b-a)%2==1) cout<<"Positive"<<endl;
	else cout<<"Negative"<<endl;

	return 0;
}
