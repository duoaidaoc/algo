#include <bits/stdc++.h>
using namespace std;
const int N = 60;
int dp[N][N][N];
int aa[N][N];
int n, m;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> aa[i][j];
		}
	}
	int tmp[N] = { 0 };
	//霍纳法则优化dp 
	for (int yy = 2; yy <= m; yy++) {
		for (int x1 = 1; x1 <= n; x1++) {
			for (int x2 = x1 + 1; x2 <= n; x2++) {
				tmp[x2] = max(tmp[x2] + aa[x1][yy - 1], dp[x1][x2][yy - 1] + aa[x1][yy - 1] + aa[x2][yy - 1]);
				dp[x1][x2][yy] = max(dp[x1][x2 - 1][yy] + aa[x2][yy - 1], tmp[x2]);
			}
		}
		memset(tmp, 0, sizeof(tmp));
	}
	int maxt = dp[1][n][m] + aa[1][m];
	for (int i = 2; i <= n - 1; i++) {
		maxt = max(maxt + aa[i][m], dp[i][n][m] + aa[i][m]);
	}
	cout << maxt + aa[n][m] << '\n';
}
