#include <bits/stdc++.h>
using namespace std;
int dp[160][160];
int n = 0;
char p[160];
char s[160];
const int inf = 0x3f3f3f3f;
int dfs(int i,int j){
	if (i > j)return inf;
    if (dp[i][j] != inf) return dp[i][j];
    if(i == j)return dp[i][j] = 1;
    if(s[i] == s[j])return dp[i][j] = min(dfs(i, j - 1),dfs(i + 1, j));
    if(s[i] != s[j]){
        for(int k = i;k <=j - 1;k++){
            dp[i][j] = min(dp[i][j], dfs(i,k) + dfs(k + 1,j));
            //printf("%d %d %d %d %d %d\n",i,j,k,dp[i][j],dp[i][k],dp[k+1][j]);
        }
        return dp[i][j];
    }
}
int f[160];
int main(){
    while(scanf("%s",p + 1) == 1){
		n = strlen(p + 1);
	    scanf("%s",s + 1);
	    memset(dp,0x3f,sizeof(dp));
	    for(int i = 1;i<=n;i++){
	        dp[i][i] = 1;
	    }
	    memset(f,0x3f,sizeof(f));
	    f[0] = 0;
	    for(int i = 1;i<=n;i++){
	    	if(p[i] == s[i]){
				f[i] = f[i - 1];
			}
			else{
				for(int j = 0;j + 1 <= i;j++){
					int tmp = dfs(j + 1,i);
					f[i] = min(f[i],f[j] + tmp);
				}
			}
		}
		cout << f[n];
	}
}
