#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int deg,dis; cin>>deg>>dis;
	int a=dis/6.0+0.5;

	int w;
	if(a<=2) w=0;
	else if(a<=15) w=1;
	else if(a<=33) w=2;
	else if(a<=54) w=3;
	else if(a<=79) w=4;
	else if(a<=107) w=5;
	else if(a<=138) w=6;
	else if(a<=171) w=7;
	else if(a<=207) w=8;
	else if(a<=244) w=9;
	else if(a<=284) w=10;
	else if(a<=326) w=11;
	else w=12;

	string dir;
	if(w==0) dir="C";
	else if(112.5<=deg && deg<337.5) dir="NNE";
	else if(337.5<=deg && deg<562.5) dir="NE";
	else if(562.5<=deg && deg<787.5) dir="ENE";
	else if(787.5<=deg && deg<1012.5) dir="E";
	else if(1012.5<=deg && deg<1237.5) dir="ESE";
	else if(1237.5<=deg && deg<1462.5) dir="SE";
	else if(1462.5<=deg && deg<1687.5) dir="SSE";
	else if(1687.5<=deg && deg<1912.5) dir="S";
	else if(1912.5<=deg && deg<2137.5) dir="SSW";
	else if(2137.5<=deg && deg<2362.5) dir="SW";
	else if(2362.5<=deg && deg<2587.5) dir="WSW";
	else if(2587.5<=deg && deg<2812.5) dir="W";
	else if(2812.5<=deg && deg<3037.5) dir="WNW";
	else if(3037.5<=deg && deg<3262.5) dir="NW";
	else if(3262.5<=deg && deg<3487.5) dir="NNW";
	else dir="N";

	cout<<dir<<" "<<w<<endl;

	return 0;
}
