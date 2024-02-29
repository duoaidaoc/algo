#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
#define ll long long

ll tre[N];
ll t, mod, m;
const int M = 200200;
int tot;
void add(int root, int l, int r, int pos, ll x) {
	if (l > r)return;
	if (l == r && r == pos) {
		tre[root] = x;
		return;
	}
	int mid = l + r >> 1;
	if (pos <= mid) {
		add(root << 1, l, mid, pos, x);
	}
	else if (pos > mid) {
		add((root << 1) | 1, mid + 1, r, pos, x);
	}
	tre[root] = max(tre[root << 1], tre[root << 1 | 1]);
}


ll qus(int root, int l, int r, int x, int y) {
	if (l > r)return 0;
	if (l == x && r == y) {
		return tre[root];
	}
	int mid = l + r >> 1;
	if (y <= mid)return qus(root << 1, l, mid, x, y);
	else if (x >= mid + 1)return qus(root << 1 | 1, mid + 1, r, x, y);
	else {
		return max(qus(root << 1, l, mid, x, mid), qus(root << 1 | 1, mid + 1, r, mid + 1, y));
	}
}
int main() {
	scanf("%lld%lld", &m, &mod);
	memset(tre, 0xc0, sizeof(tre));
	while (m--) {
		getchar();
		char s[10];
		ll x;
		scanf("%s%lld", s, &x);
		if (s[0] == 'A') {
			add(1, 1, M, ++tot, (x + t) % mod);
		}
		else {
			t = qus(1, 1, M, tot - x + 1, tot);
			printf("%lld\n", t);
		}
	}
}
