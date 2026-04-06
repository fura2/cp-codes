#include <algorithm>
#include <iostream>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	cout<<max(c-a+b,0)<<endl;

	return 0;
}
