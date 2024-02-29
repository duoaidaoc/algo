#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 202020;

int n, q, k;
int a[N];

unordered_map<int, int>cnt;
ll res[N];
vector<array<int, 4> >qe;
ll ans = 0;

void add(int x) {
	ans += 1ll * cnt[k ^ a[x]];
	cnt[a[x]]++;
}

void del(int x) {
	cnt[a[x]]--;
	ans -= 1ll * cnt[k ^ a[x]];
}

bool cmp(array<int, 4> x, array<int, 4> y) {
	if (x[3] == y[3])return x[1] < y[1];
	return x[3] < y[3];
}
int main() {
	cin >> n >> q >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] = a[i] ^ a[i - 1];
	}
	int sqn = int(sqrt(n));
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		qe.push_back({ x - 1,y,i,x / sqn });
	}
	sort(qe.begin(), qe.end(), cmp);
	int l = 0, r = -1;
	for (int i = 0; i <= q - 1; i++) {
		while (r < qe[i][1]) { r++; add(r); }
		while (r > qe[i][1]) { del(r); r--; }
		while (l < qe[i][0]) { del(l); l++; }
		while (l > qe[i][0]) { l--; add(l); }
		res[qe[i][2]] = ans;
	}
	for (int i = 1; i <= q; i++) {
		cout << res[i] << '\n';
	}
}
