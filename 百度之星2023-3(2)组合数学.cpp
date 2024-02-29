#define ll long long

#include<bits/stdc++.h> 
using namespace std;
ll n,m,k;
const int mod = 998244353;

ll mdpow(ll x,ll n){
	if(n == 0)return 1;
	if(n == 1)return x % mod;
	if(n % 2 == 0)return mdpow((x * x) % mod,n / 2) % mod;
	return mdpow((x * x)% mod,n / 2) % mod * x % mod;
}

ll invv(ll x){
	return mdpow(x,mod - 2);
}

const int N = 1e7+10;
ll Cna[N];
ll Cmx[N];
ll inv[N];

void init(){
	Cna[0] = Cmx[0] = inv[1] = inv[0] = 1;
	Cna[1] = n;
	Cmx[1] = m;
	for(int i = 2;i <= max(n,m);i++){
		inv[i] = inv[mod % i] * (mod - mod / i) % mod;
	}
	for(int i = 2;i<= n;i++){
		Cna[i] = Cna[i - 1] * (n + 1 - i) % mod * inv[i] % mod;
	}
	for(int i = 2;i<= m;i++){
		Cmx[i] = Cmx[i - 1] * (m + 1 - i) % mod * inv[i] % mod;
	}
}

int main( )
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	ll ans = 0;
	cin >> n >> m >> k;
	init();

	for(ll x = 0;x <= m / 2; x++){
		if(2 * x == m){
			if(k - n * m + x * n == 0){
				ans += mdpow(2,n - 1) * Cmx[x] % mod;
                ans %= mod;
				//printf("ans = %lld\n",ans);
			}
		}
		else{
			if((k - n * m + x * n) % (2 * x - m) == 0){
				ll a = (k - n * m + x * n) / (2 * x - m);
				if(a < 0 || a > n) continue;
				ans += Cna[a] * Cmx[x] % mod;
                ans %= mod;
				//printf("Cmx : %lld ,Cna : %lld, x = %lld, a = %lld, ans = %lld\n",Cmx,Cna,x,a,ans);
			}
		}
	}
	printf("%lld\n",ans % mod);
    return 0;
}
