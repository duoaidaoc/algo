#include <bits/stdc++.h>
using namespace std;
const int N = 1010,inf = 1 << 29;
#define ll long long
ll gcd(ll x,ll y){
  if(y == 1)return 1;
  if(y == 0)return x;
  return gcd(y, x%y);
}

int n,m,q;
ll a[N][N];
ll sum[5][N][N];

void upd(int x,int y){
	int gx = (gcd(a[x - 1][y],a[x][y]) == 1);
	int gy = (gcd(a[x][y - 1],a[x][y]) == 1);
	for(int i = 0;i <= q;i++){
		sum[i][x][y] = max((i + gx <= q) * sum[i + gx][x - 1][y],(i + gy <= q) * sum[i + gy][x][y - 1]);
		if(sum[i][x][y] != 0)sum[i][x][y] += a[x][y];
	}
}

int main()
{
	cin >> n >> m >> q;
	for(int i = 1; i<=n;i++)
		for(int j = 1; j<=m;j++)
  			cin >> a[i][j];
  	for(int i = 1; i<=n;i++)
		a[i][0] = 1;
	for(int i = 1; i<=m;i++)
		a[0][i] = 1;
	sum[q][1][1] = a[1][1];
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(i == 1 && j == 1)continue;
			upd(i,j);
		}
	}
	// debug
	/*
		cout << '\n';
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			cout << sum[1][i][j] << ' ';
		}
		cout << '\n';
	}
		cout << '\n';
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			cout << sum[0][i][j] << ' ';
		}
		cout << '\n';
	}
	*/
	ll maxt = 0;
	for(int i = 0;i <= q;i++)maxt = max(maxt,sum[i][n][m]);
	if(maxt == 0)cout << -1;
	else cout << maxt;
	return 0;
}
