#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N = 1e3 + 10, M = 1e4 + 10;
vector<int>sons [N];
int a[N],w[N],dp[N][M];
int l[N],r[N],id[N],siz[N];
int tot;
const int inf = 1 << 29;
void dfs(int u){
	l[u] = ++tot;
	id[tot] = u;
	int sz = sons[u].size();
	for(int i = 0;i<sz;i++){
		dfs(sons[u][i]);
	}
	r[u] = tot;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 2;i<=n;i++){
		int x;
		scanf("%d",&x);
		sons[x].push_back(i);
	}
	for(int i = 1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i = 1;i<=n;i++)
		scanf("%d",&w[i]);
	dfs(1);
	for(int i = 1;i<=m;i++)
		dp[n + 1][i] = -inf;
	sz[n + 1] = 1;
	for(int i = n;i >= 1;i--){
		int u = id[i];
		for(int x = 0;x <= m;x++){
			dp[i][x] = dp[r[u] + 1][x];
			if(x >= w[u])
				dp[i][x] = max(dp[i][x],dp[i + 1][x - w[u]] + a[u]);
		}
	}
	for(int i = 0;i<=m;i++){
		if(dp[1][i] > 0)printf("%d\n",dp[1][i]);
		else printf("0\n");
	}
}
