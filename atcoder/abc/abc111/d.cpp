#include <iostream>
#include <string>
#include <vector>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

/*
	tar: even
		d_1 = 1, d_{i} = 2^{i-2} (2<=i<=m)
	find s_i in {+1, -1} s.t. s_1 d_1 + ... + s_m d_m = tar
*/
string solve2(int tar,int m){
	if(tar<0){
		string s=solve2(-tar,m);
		for(char &c:s) c=(c=='+')?'-':'+';
		return s;
	}

	if(m==2){
		if(tar==0) return "+-";
		else       return "++";
	}

	return solve2(tar-(1<<(m-2)),m-1)+"+";
}

/*
	tar: even
		m = 32
		d_1 = 1, d_{i} = 2^{i-2} (2<=i<=32)
	tar: odd
		m = 33
		d_1 = 1, d_{i} = 2^{i-2} (2<=i<=32), d_{33} = 1
	find s_i in {+1, -1} s.t. s_1 d_1 + ... + s_m d_m = tar
*/
string solve(int tar){
	if(tar%2!=0) return solve(tar-1)+"+";
	return solve2(tar,32);
}

int main(){
	int n; cin>>n;
	vector<int> x(n),y(n);
	rep(i,n) cin>>x[i]>>y[i];

	int par=((x[0]+y[0])%2+2)%2;
	rep(i,n) if(((x[i]+y[i])%2+2)%2!=par) {
		cout<<"-1"<<endl;
		return 0;
	}

	vector<int> d(1,1);
	rep(i,31) d.emplace_back(1<<i);
	if(par==1) d.emplace_back(1);

	int m=d.size();
	cout<<m<<endl;
	rep(i,m) cout<<d[i]<<' ';
	cout<<endl;

	rep(i,n){
		int u=x[i]+y[i]; // super clever!!
		int v=x[i]-y[i];

		string s1=solve(u);
		string s2=solve(v);

		string ans;
		rep(j,m){
			if     (s1[j]=='+' && s2[j]=='+') ans+='R';
			else if(s1[j]=='+' && s2[j]=='-') ans+='U';
			else if(s1[j]=='-' && s2[j]=='+') ans+='D';
			else if(s1[j]=='-' && s2[j]=='-') ans+='L';
		}
		cout<<ans<<endl;
	}

	return 0;
}
