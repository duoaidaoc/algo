#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2020,M = 120;
vector<int>e[N];
const ll inf = 1 << 59;
int fa[N];
ll val[N];
ll sum[N];
int del[N];
int rt = 1;
int n,m;
void dfs(int u){
	sum[u] = val[u];
	for(auto v : e[u]){
		dfs(v);
		sum[u] += sum[v];
	}
}
int find(int u,ll aim){
	int ans = u;
	for(auto v: e[u]){
		if(del[v])continue;
		if(sum[v] * 2 > aim) v = find(v , aim);
		if(abs(2 * sum[ans] - aim) > abs(2 * sum[v] - aim)) ans = v;
		else if(abs(2 * sum[ans] - aim) == abs(2 * sum[v] - aim))ans = min(ans,v);
	}
	return ans;
}
int rt_empty(int u){
	for(auto v : e[u]){
		if(!del[v])return 0;
	}
	return 1;
}
int main(){
	cin >> n >> m;
	for(int i = 1;i<= n;i++){
		cin >> val[i];
	}
	for(int i = 2;i<= n;i++){
		cin >> fa[i];
		e[fa[i]].push_back(i);
	}
	int que;
	while(m--){
		cin >> que;	
		dfs(1);
		rt = 1;
		memset(del,0,sizeof(del));
		set<int>fas;
		int ptr = que;
		while(ptr != fa[rt]){
			fas.insert(ptr);
			ptr = fa[ptr];
		}
		int q = find(rt, sum[rt]);
		while(!rt_empty(rt)){
			cout << q << ' ';
			if(fas.count(q)){
				rt = q;
			}
			else{
				ptr = fa[q];
				del[q] = 1;
				while(ptr != fa[rt]){
					sum[ptr] -= sum[q];
					ptr = fa[ptr];
				}
			}
			q = find(rt, sum[rt]);
		}
		cout << '\n';
	}
}
