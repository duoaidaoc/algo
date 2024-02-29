#include<bits/stdc++.h>
using namespace std;
const int N = 5013;
struct{
	int to;
	int nex;
	int val;
}e[N * N];
int tot = 0, head[N];
void add(int x,int y,int z){
	e[++tot].to = y;
	e[tot].val = z;
	e[tot].nex = head[x];
	head[x] = tot;
}
int n,m;
int dist[N];
int inqueuecnt[N];
int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&y,&x,&z);
		add(x,y,z);
	}
	for(int i = 1;i<=n;i++){
		add(0,i,0);
	}
	memset(dist,0x3f,sizeof(dist));
	queue<int>qe;
	dist[0] = 0;
	qe.push(0);
	while(!qe.empty()){
		int u = qe.front();qe.pop();
		for(int eg = head[u];eg;eg = e[eg].nex){
			int v = e[eg].to;			
		//	printf("OUT: %d %d %d %d %d\n",u,v,e[eg].val,dist[u],dist[v]);
			if(dist[v] > dist[u] + e[eg].val){
		//		printf("    %d %d %d %d %d\n",u,v,e[eg].val,dist[u],dist[v]);
				if(inqueuecnt[v] > n){
					puts("NO");
					return 0;
				}
				qe.push(v);
				dist[v] = dist[u] + e[eg].val;
				inqueuecnt[v]++;
			}
		}
	}
	for(int i = 1;i<=n;i++){
		printf("%d ",dist[i]);
	}
}
