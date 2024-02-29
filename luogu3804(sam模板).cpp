#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e6 + 10;

struct node {
	int nex[26];
	int len;
	int fail;
	int indeg;
}nd[N];
int las = 1, tot = 1;
int sz[N];
void ins(int x) {
	nd[++tot].len = nd[las].len + 1;
	int tmp = las;
	las = tot;
	sz[tot] = 1;
	while (tmp != 0 && nd[tmp].nex[x] == 0) {
		nd[tmp].nex[x] = tot;
		tmp = nd[tmp].fail;
	}
	if (tmp == 0) {
		nd[tot].fail = 1;
	}
	else {
		int y = nd[tmp].nex[x];
		if (nd[y].len == nd[tmp].len + 1) {
			nd[tot].fail = y;
		}
		else {
			int now = tot;
			nd[++tot].len = nd[tmp].len + 1;
			memcpy(nd[tot].nex, nd[y].nex, sizeof(nd[y].nex));
			nd[tot].fail = nd[y].fail;
			nd[y].fail = tot;
			nd[now].fail = tot;
			while (nd[tmp].nex[x] == y) {
				nd[tmp].nex[x] = tot;
				tmp = nd[tmp].fail;
			}
		}
	}
}

int c[N],k[N];
int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		ins(s[i] - 'a');
	}
	//将nd中的点按照最大长度桶排序。 
	for (int i = 1; i <= tot; i++)c[nd[i].len]++;
	for (int i = 1; i <= tot; i++)c[i] += c[i - 1];
	for (int i = 1; i <= tot; i++)k[c[nd[i].len]--] = i;
	for (int i = tot; i >= 1; i--) {
		int id = k[i];
		sz[nd[id].fail] += sz[id];
	}
	ll ans = 0;
	for (int i = 1; i <= tot; i++) {
		if (sz[i] >= 2) {
			ans = max(ans, 1ll * sz[i] * nd[i].len);
		}
	}
	cout << ans;
}
