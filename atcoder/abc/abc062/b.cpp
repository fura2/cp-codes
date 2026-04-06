#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w; cin>>h>>w;
	cout<<string(w+2,'#')<<endl;
	rep(i,h){
		string s; cin>>s;
		cout<<"#"<<s<<"#"<<endl;
	}
	cout<<string(w+2,'#')<<endl;
	return 0;
}
