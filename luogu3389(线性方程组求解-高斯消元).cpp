#include<bits/stdc++.h>
using namespace std;

double a[105][105];
double eps = 1e-7;

int main(){
	int n;scanf("%d",&n);
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=n + 1;j++)
			scanf("%lf",&a[i][j]);
	for(int i = 1;i<=n;i++){
		int maxt = i;
		for(int j = i + 1;j <= n + 1;j++)
			if(fabs(a[j][i])>fabs(a[maxt][i]))maxt = j;
		for(int j= 1; j<= n + 1; j++)swap(a[i][j],a[maxt][j]);
		if(fabs(a[i][i]) < eps){
			puts("No Solution");
			return 0;
		}
		for(int j = n + 1;j >= 1;j--){
			a[i][j] /= a[i][i];
		}
		for(int j = 1;j<=n;j++)
			if(j != i){
				double tmp = a[j][i] / a[i][i];
				for(int k = 1;k<=n + 1;k++){
					a[j][k] -= a[i][k] * tmp;
				}
			}
	}
	for(int i = 1;i<=n;i++)printf("%.2f\n",a[i][n + 1]);
	return 0;
}

