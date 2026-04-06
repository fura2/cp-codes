#include <bits/stdc++.h>

using namespace std;

int main(){
	int day[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

	int y,m,d; scanf("%d/%d/%d",&y,&m,&d);
	while(y%(m*d)!=0){
		bool leap=(y%400==0||(y%100!=0&&y%4==0));
		if(leap) day[2]++;
		d++;
		if(d-1==day[m]) m++, d=1;
		if(m==13) y++, m=1;
		if(leap) day[2]--;
	}
	printf("%d/%02d/%02d\n",y,m,d);

	return 0;
}
