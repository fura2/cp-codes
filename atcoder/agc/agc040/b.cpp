#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

struct interval{ int a,b; };

int case1(vector<interval> I){
	int n=I.size();
	multiset<int> L,R;
	rep(i,n){
		L.emplace(I[i].a);
		R.emplace(I[i].b);
	}

	int res=0;
	rep(i,n){
		int l1=I[i].a,r1=I[i].b;
		L.erase(L.find(l1));
		R.erase(R.find(r1));
		int l2=*L.rbegin();
		int r2=*R.begin();
		res=max(res,(r1-l1)+max(r2-l2,0));
		L.emplace(l1);
		R.emplace(r1);
	}
	return res;
}

int case2(vector<interval> I){
	int n=I.size();
	sort(I.begin(),I.end(),[](const interval& I,const interval& J){
			return make_pair(I.a,-I.b)<make_pair(J.a,-J.b);
	});

	int p=0,q=0;
	rep(i,n){
		if(make_pair(I[i].b,-I[i].a)<make_pair(I[p].b,-I[p].a)) p=i;
		if(make_pair(I[i].a,-I[i].b)>make_pair(I[q].a,-I[q].b)) q=i;
	}

	multiset<int> L1,R2;
	rep(i,n) R2.emplace(I[i].b);

	int res=0;
	int r1=I[p].b; L1.emplace(I[p].a);
	int l2=I[q].a; R2.emplace(I[q].b);
	rep(i,n+1){
		int l1=*L1.rbegin();
		int r2=*R2.begin();
		res=max(res,max(r1-l1,0)+max(r2-l2,0));
		if(i<n){
			L1.insert(I[i].a);
			R2.erase(R2.find(I[i].b));
		}
	}
	return res;
}

int main(){
	int n; scanf("%d",&n);
	vector<interval> I(n);
	rep(i,n) scanf("%d%d",&I[i].a,&I[i].b), I[i].a--;

	printf("%d\n",max(case1(I),case2(I)));

	return 0;
}
