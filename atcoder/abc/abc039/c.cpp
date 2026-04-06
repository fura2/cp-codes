#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	s=s.substr(0,12);
	if     (s=="WBWBWWBWBWBW") cout<<"Do\n";
	else if(s=="WBWWBWBWBWWB") cout<<"Re\n";
	else if(s=="WWBWBWBWWBWB") cout<<"Mi\n";
	else if(s=="WBWBWBWWBWBW") cout<<"Fa\n";
	else if(s=="WBWBWWBWBWWB") cout<<"So\n";
	else if(s=="WBWWBWBWWBWB") cout<<"La\n";
	else                       cout<<"Si\n";
	return 0;
}
