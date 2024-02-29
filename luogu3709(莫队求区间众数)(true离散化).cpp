#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 202020;

int n,q;
vector<pair<int,int> >tmp;
int a[N];

vector<array<int,4> >qe;
int ans = 0;

int cnt[N];
int rpcnt[N];

int res[N];
void add(int x){
	rpcnt[cnt[a[x]]] = max(0,rpcnt[cnt[a[x]]] - 1);
	cnt[a[x]]++;
	rpcnt[cnt[a[x]]]++;
	ans = max(ans,cnt[a[x]]);
}

void del(int x){
	rpcnt[cnt[a[x]]] = max(0,rpcnt[cnt[a[x]]] - 1);
	cnt[a[x]]--;
	rpcnt[cnt[a[x]]]++;
	if(!rpcnt[ans]) ans--;
}

bool cmp(array<int,4> x,array<int,4> y){
	if(x[3] == y[3])return x[1] < y[1];
	return x[3] < y[3];
}

int main(){
	cin >> n >> q;
	for(int i = 1;i<=n;i++){
		int x;
		cin >> x;
		tmp.push_back({x,i});
	}
	sort(tmp.begin(),tmp.end());
	int j = 0;
	for(int i = 0;i<n;i++){
		if(i == 0 || tmp[i].first != tmp[i - 1].first)
			j++;
		a[tmp[i].second] = j;
	}
	
	int sqn = int(sqrt(n));
	for(int i = 1;i<=q;i++){
		int x,y;
		cin >> x >> y;
		qe.push_back({x,y,i,x / sqn});
	}
	sort(qe.begin(),qe.end(),cmp);
	int l = 0,r = 0;
	for(int i = 0;i<=q - 1;i++){
		//cout << qe[i][0] << ' ' << qe[i][1] << '\n';
		while(r < qe[i][1]){r++;add(r);}
		while(r > qe[i][1]){del(r);r--;}
		while(l < qe[i][0]){del(l);l++;}
		while(l > qe[i][0]){l--;add(l);}
		res[qe[i][2]] = -ans;
		//cout << l << ' ' << r << ' ' << ans << '\n';
	}
	for(int i = 1;i<=q;i++){
		cout << res[i] << '\n';
	}
}
