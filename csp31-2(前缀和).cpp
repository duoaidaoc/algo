#include<bits/stdc++.h>
using namespace std;

double k[100020];
double aa[100020];

int main(){
	int n,m;
	cin>>n>>m;
	k[0] = 1;
	for(int i = 1;i<=n;i++){
		int t;
		cin >> t;
		double tmp1 = 1.0,tmp2 = 0.0;
		if(t == 1){
			cin >> tmp1;
		}
		else{
			cin >> tmp2;
		}
		k[i] = tmp1 * k[i - 1];
		aa[i] = tmp2 + aa[i - 1];
	}
	for(int i = 1;i <= m;i++){
		
		int a,b;
		double x,y;
		cin>>a>>b>>x>>y;
		x *= k[b] / k[a-1];
		y *= k[b] / k[a-1];
		double xx,yy;
		xx = x * cos(aa[b] - aa[a-1]) - y*sin(aa[b] - aa[a-1]);
		yy = x * sin(aa[b] - aa[a-1]) + y*cos(aa[b] - aa[a-1]);
		printf("%.3lf %.3lf\n",xx,yy);
	}
}
