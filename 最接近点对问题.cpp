#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 1e6+20;
const int inf = 1 << 29;
struct node{
	double x;
	double y;
}nodes[N];

struct res{
	double x1,y1,x2,y2;
	double dist;
};
res ans = {0,0,inf,inf,inf};
void upd(int i,int j){
	double dist = sqrt((nodes[i].x - nodes[j].x) * (nodes[i].x - nodes[j].x) + (nodes[i].y - nodes[j].y) * (nodes[i].y - nodes[j].y));
	if(dist < ans.dist)ans.x1 = nodes[i].x,ans.y1 = nodes[i].y,ans.x2 = nodes[j].x,ans.y2 = nodes[j].y,ans.dist = dist;
}

bool cmp(node xx,node yy){
	if(xx.x==yy.x)return xx.y<yy.y;
	return xx.x<yy.x;
}

bool merge_cmp(node xx,node yy){
	return xx.y<yy.y;
}

void solve(int disl, int disr){
	if(disl + 3 <= disr){
		for(int i = disl;i<=disr - 1;i++)
			for(int j = i + 1;j <= disr;j++)
				upd(i,j);
		sort(nodes + disl,nodes + disr + 1, merge_cmp);
		return;
	}
	int mid = disl + disr >> 1;
	solve(disl,mid);
	solve(mid + 1,disr);
	inplace_merge(nodes + disl, nodes + mid + 1, nodes + disr + 1, merge_cmp);
	vector<int>tmp;
	for(int i = disl ;i <= disr ;i++){
		if(abs(nodes[i].x - nodes[mid].x) <= ans.dist){
			for(int j = 0; j < tmp.size() && nodes[i].y - nodes[tmp[j]].y < ans.dist;j++){
				upd(i,j);
			}
			tmp.push_back(i);
		}
	}
	
}

int main(){
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> nodes[i].x >> nodes[i].y;
	}
	sort(nodes + 1,nodes + n + 1,cmp);
	solve(1,n);
	printf("%.2lf",ans.dist);
}
