#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n,a[25],dir[30][30];
int topo[25],vis[30],inde[30];
void dfs(int u,int cnt){
	topo[cnt] = u;
	if(cnt == n - 1){
		for(int i = 0;i<n;i++)printf("%c",topo[i] + 'a');
		printf("\n");
		return;
	}
	vis[u] = 1;
	for(int i = 0;i<n;i++)if(!vis[a[i]]&&dir[u][a[i]])inde[a[i]]--;
	for(int i = 0;i<n;i++)if(!inde[a[i]]&&!vis[a[i]])dfs(a[i],cnt+1);
	for(int i = 0;i<n;i++)if(!vis[a[i]]&&dir[u][a[i]])inde[a[i]]++;
	vis[u] = 0;
}

int main(){
	char s[100];
	int len;
	while(gets(s)!=NULL){
		memset(dir,0,sizeof(dir));
		memset(vis,0,sizeof(vis));
		memset(inde,0,sizeof(inde));
		len = strlen(s);
		n = 0;
		for(int i = 0;i<len;i++)
		if(s[i] <= 'z' && s[i] >= 'a')
		a[n++] = s[i] - 'a';
		sort(a,a + n);
		gets(s);
		len = strlen(s);
		int st = 1;
		for(int i = 0;i<=len;i++){
			int b,e;
			if(st&&s[i]<='z'&&s[i]>='a'){
				st = 0,b = s[i] - 'a';
				continue;
			}
			if(!st&&s[i]<='z' && s[i]>='a'){
				st = 1,e = s[i] - 'a';
				dir[b][e] = 1;
				inde[e]++;
				continue;
			}
		}
		for(int i = 0;i < n ;i++)
			if(!inde[a[i]])dfs(a[i],0);
		printf("\n");
	}
	return 0;
}

