#include<bits/stdc++.h>
using namespace std;

const int N = 320,M = 320;
int dp[N][M];
int n,m;
vector<int> son[N];
int l[N],r[N],id[N],val[N];
int tot = -1,inf = 1 << 29;
void dfs(int u){
	l[u] = ++tot;
	id[tot] = u;
	for(auto &v : son[u]){
		dfs(v);
	}
	r[u] = tot;
}

int main(){
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		int x,y;
		cin >> x >> y;
		son[x].push_back(i);
		val[i] = y;
	}
	m++;
	for(int i = 1;i<= m;i++){
		dp[n + 1][i] = -inf;
	}
	dfs(0);
	for(int i = n;i>=0;i--){
		int u = id[i];
		for(int j = 1; j <= m;j++){
			dp[i][j] = dp[r[u] + 1][j];
			if(j >= 1)
			dp[i][j] = max(dp[i][j],dp[i + 1][j - 1] + val[u]);
		}
	}
	if(dp[0][m] > 0)cout << dp[0][m];
	else cout << 0;
	
}
