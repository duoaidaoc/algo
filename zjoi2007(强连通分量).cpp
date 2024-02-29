#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <queue>
#include <vector>
#include <unordered_map>
#include <map>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;
const int N = 2e6 + 10;

vector<vector<int>>scc;
vector<int>e[N];

int dfn[N], ins[N],top[N];
int bel[N], dp[N], sum[N];
int vis[N];
int tot = 0;
stack<int>st;
void dfs(int root) {
	dfn[root] = top[root] = ++tot;
	st.push(root);
	ins[root] = 1;
	for (auto& v : e[root]) {
		if (!dfn[v])dfs(v);
		if (ins[v]) top[root] = min(top[root], top[v]);
	}
	if (top[root] == dfn[root]) {
		vector<int>tmp;
		while (true) {
			int x = st.top(); st.pop();
			bel[x] = scc.size();
			ins[x] = 0;
			tmp.push_back(x);
			if (x == root)break;
		}
		scc.push_back(tmp);
	}
}

int n, m, x;

int main() {
	cin >> n >> m >> x;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) {
		if(!dfn[i])dfs(i);
	}
	int len = scc.size();
	int ans = 0;
	int maxsum = 0;
	for (int i = 0; i <= len - 1; i++) {
		dp[i] = 0;
		sum[i] = 1;
		for (auto ele : scc[i]) {
			for (auto nxt : e[ele]) {
				if (vis[bel[nxt]] && bel[nxt] != i)continue;
				vis[bel[nxt]] = 1;
				if (dp[bel[nxt]] > dp[i])dp[i] = dp[bel[nxt]], sum[i] = 0;
				if (dp[i] == dp[bel[nxt]]) sum[i] = (sum[i] + sum[bel[nxt]]) % x;
			}
		}
		dp[i] += scc[i].size();
		if (dp[i] > ans) {
			ans = dp[i];
			maxsum = 0;
		}
		if (dp[i] == ans) {
			maxsum = (maxsum + sum[i]) % x;
		}
		for (auto ele : scc[i])for (auto nxt : e[ele])vis[bel[nxt]] = 0;
	}
	cout << ans << endl << maxsum << endl;

}

