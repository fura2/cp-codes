#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
/*
	a < b < c として, 最大 - 最小は
	c - a
	->
	(b+c)/2 - (a+b)/2 = (c-a)/2
	->
	(a+b+2c)/4 - (2a+b+c)/4 = (c-a)/4
*/
	int a,b,c; scanf("%d%d%d",&a,&b,&c);

	set<tuple<int,int,int>> S;
	while(S.count(make_tuple(a,b,c))==0){
		if(a%2==1 || b%2==1 || c%2==1) return printf("%lu\n",S.size()),0;
		S.emplace(a,b,c);
		tie(a,b,c)=make_tuple((b+c)/2,(a+c)/2,(a+b)/2);
	}
	puts("-1");

	return 0;
}
