#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int a=stoi(s.substr(0,2));
	int b=stoi(s.substr(2));

	bool f1=(1<=b && b<=12);
	bool f2=(1<=a && a<=12);
	if     ( f1 &&  f2) cout<<"AMBIGUOUS"<<endl;
	else if( f1 && !f2) cout<<"YYMM"<<endl;
	else if(!f1 &&  f2) cout<<"MMYY"<<endl;
	else                cout<<"NA"<<endl;

	return 0;
}
