#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	if     (s=="SUN") cout<<"7\n";
	else if(s=="MON") cout<<"6\n";
	else if(s=="TUE") cout<<"5\n";
	else if(s=="WED") cout<<"4\n";
	else if(s=="THU") cout<<"3\n";
	else if(s=="FRI") cout<<"2\n";
	else if(s=="SAT") cout<<"1\n";
	return 0;
}
