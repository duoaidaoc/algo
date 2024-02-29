#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 101;
ll low[N][N],dust[N][N],cal[N][N];
int n;
ll aim;
void prin_cal(){
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			cout << cal[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}
bool calc(ll x){
	ll u = x/n,v = x%n;
	for(int i = 1;i<=n;i++){
		for(int j = i + 1;j<=n;j++){
			cal[j][i] = cal[i][j] = max(dust[i][j] - u * 2 - (i <= v) - (j <= v), low[i][j]);
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			for(int k = 1;k<=n;k++){
				cal[i][k] = min(cal[i][k],cal[i][j] + cal[j][k]);
			}
		}
	}
	ll ans = 0;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j <=n;j++){
			ans += cal[i][j];
		}
	}
	//prin_cal();
	if(ans > aim)return false;
	else return true;
}
bool can(){
	for(int i = 1;i<=n;i++){
		for(int j = 1;j <=n;j++){
			cal[i][j] = low[i][j];
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			for(int k = 1;k<=n;k++){
				cal[i][k] = min(cal[i][k],cal[i][j] + cal[j][k]);
			}
		}
	}
	ll ans = 0;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j <=n;j++){
			ans += cal[i][j];
		}
	}
	if(ans > aim)return false;
	else return true;
}
int main(){
	cin >> n >>  aim;
	for(int i = 1;i<=n;i++)for(int j = 1;j<=n;j++) cin >> dust[i][j];
	for(int i = 1;i<=n;i++)for(int j = 1;j<=n;j++) cin >> low[i][j];
	int l = 0;
	if(!can()){
		cout << "-1\n";
		return 0;
	}
	for(int i = 30;i>=0;i--){
		if(!calc(l + (1ll << i))){
			l += 1ll << i;
		}
	}
	cout << l + 1;
	
}
