#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	int a=n/1000,b=n/100%10,c=n/10%10,d=n%10;

	if     (a+b+c+d==7){ cout<<a<<"+"<<b<<"+"<<c<<"+"<<d<<"=7"<<endl; }
	else if(a+b+c-d==7){ cout<<a<<"+"<<b<<"+"<<c<<"-"<<d<<"=7"<<endl; }
	else if(a+b-c+d==7){ cout<<a<<"+"<<b<<"-"<<c<<"+"<<d<<"=7"<<endl; }
	else if(a+b-c-d==7){ cout<<a<<"+"<<b<<"-"<<c<<"-"<<d<<"=7"<<endl; }
	else if(a-b+c+d==7){ cout<<a<<"-"<<b<<"+"<<c<<"+"<<d<<"=7"<<endl; }
	else if(a-b+c-d==7){ cout<<a<<"-"<<b<<"+"<<c<<"-"<<d<<"=7"<<endl; }
	else if(a-b-c+d==7){ cout<<a<<"-"<<b<<"-"<<c<<"+"<<d<<"=7"<<endl; }
	else if(a-b-c-d==7){ cout<<a<<"-"<<b<<"-"<<c<<"-"<<d<<"=7"<<endl; }

	return 0;
}
