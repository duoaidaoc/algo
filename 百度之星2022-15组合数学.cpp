#include<bits/stdc++.h> 
#define ll long long
using namespace std;
const int N = 100010;
int n,m,k;
bool cmp(array<int,2>&a, array<int,2>&b){
	if(a[0] < b[0] && a[1] < b[1])return 1;
	if(a[0] == b[0] && a[1] < b[1])return 1;
	if(a[0] < b[0] && a[1] == b[1])return 1;
	return 0;
}
const int mod = 998244353;
ll fac[2 * N],fnv[2 * N], inv[N];
ll aa[N],bb[N];
vector<array<int,2>>node;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i<=k;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		node.push_back({x,y});
	}
	sort(node.begin(),node.end(),cmp);
	for(int i = 0;i < k;i++){
		int a = node[i][0],b = node[i][1];
		aa[i] = fac[a + b] * fnv[a] % mod  * fnv[b] % mod;
		ll mus = 0;
		for(int j = 0;j < i;j++){
			int _a = node[j][0],_b = node[j][1];
			if(cmp(node[j],node[i])){
				mus = (mus + fac[a - _a + b - _b] * fnv[a - _a] * fnv[b - _b])
			}
		} 
	}
    return 0;
}

