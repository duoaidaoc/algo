#include <iostream>
using namespace std;

const int N = 1e6+10;
int a[N];
int st[31][N];
int lg[N];
int dp[N]; //以a结尾的最短gcd为1的数字串 
int gcd(int x,int y){
	if(y == 0) return x;
	return gcd(y,x%y);
}

int getgcd(int l,int r){
	if(r < l)return -1;
	int i = lg[r - l + 1];
	return gcd(st[i][l],st[i][(r - (1 << i)) + 1]);
}

int main(){
	int n;
	cin >> n;
	int cnt1 = 0;
	for(int r = 1;r <= n;r++){
		cin >> a[r];
		st[0][r] = a[r];
		cnt1 += (a[r] == 1);
	}
	if(cnt1 > 0){
		cout << n - cnt1 << '\n';
		return 0;
	}
	for(int i = 1; (1 << i) <= n; i++){
		for(int j = 1;j<= n;j++){
			st[i][j] = gcd(st[i - 1][j],st[i - 1][j + (1 << (i - 1))]); //j, ...,j + (1 << i) - 1 
		}
	}
	for(int i = 2;i<=n;i++){
		lg[i] = lg[i >> 1] + 1;
	}
	dp[0] = dp[1] = -1;
	for(int i = 2;i <= n;i++){
		if(dp[i - 1] == -1){
			if(getgcd(1,i) == 1){
				int j = 1;
				while(getgcd(j,i) == 1)j++;
				dp[i] = j - 1;
			}
			else dp[i] = -1;
		}
		else{
			int j = dp[i - 1] + 1;
			while(getgcd(j,i) == 1)j++;
			dp[i] = j - 1;
		}
	}
	int mint = 0x3f3f3f3f;
	for(int i = 2;i<=n;i++){
		if(dp[i] != -1)
			mint = min(mint,i - dp[i] + 1);
	}
	if(mint == 0x3f3f3f3f){
		cout << "-1\n";
		return 0;
	}
	cout << mint + n - 2 << '\n';
}

 
