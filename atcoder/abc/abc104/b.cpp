#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();
	if(s[0]=='A'){
		if(count(s.begin(),s.end(),'C')==1){
			int pos=find(s.begin(),s.end(),'C')-s.begin();
			if(2<=pos && pos<n-1){
				bool ok=true;
				rep(i,n) if(i!=0 && i!=pos && isupper(s[i])) ok=false;
				if(ok){
					cout<<"AC"<<endl;
					return 0;
				}
			}
		}
	}
	cout<<"WA"<<endl;

	return 0;
}
