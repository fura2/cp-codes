#include <iostream>
#include <string>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();

	bool ok=true;
	if(s[0]=='0' || s[n-1]=='1') ok=false;
	rep(i,n/2) if(s[i]!=s[n-i-2]) ok=false;
	if(!ok){
		cout<<-1<<endl;
		return 0;
	}

	int u=1;
	rep(i,n-1){
		int v=i+2;
		cout<<u<<" "<<v<<endl;
		if(s[i]=='1') u=v;
	}

	return 0;
}
