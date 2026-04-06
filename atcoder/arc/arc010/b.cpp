#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class T>
vector<pair<T,int>> run_length_encoding(const vector<T>& a){
	vector<pair<T,int>> res;
	int n=a.size(),pre=0;
	rep(i,n) if(i==n-1 || a[i]!=a[i+1]) res.emplace_back(a[i],i-pre+1), pre=i+1;
	return res;
}

int main(){
	const int DAY[]={-1,31,29,31,30,31,30,31,31,30,31,30,31};

	int n; scanf("%d",&n);
	set<pair<int,int>> H;
	rep(i,n){
		int m,d; scanf("%d/%d",&m,&d);
		H.emplace(m,d);
	}

	vector<bool> seq;
	int m=1,d=1,week=0,cnt=0;
	while(m<=12){
		if(week==0 || week==6){
			if(H.count({m,d})==1) cnt++;
			seq.emplace_back(true);
		}
		else if(cnt>0){
			if(H.count({m,d})==1) cnt++;
			seq.emplace_back(true);
			cnt--;
		}
		else if(H.count({m,d})==1){
			seq.emplace_back(true);
		}
		else{
			seq.emplace_back(false);
		}

		d++;
		if(d>DAY[m]) d=1, m++;
		week=(week+1)%7;
	}

	int ans=0;
	for(auto p:run_length_encoding(seq)) if(p.first) ans=max(ans,p.second);
	printf("%d\n",ans);

	return 0;
}
