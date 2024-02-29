#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
const int N = 5e3+20;
vector<pair<int,int>>e[N];
int n,m,vis[N];
int main(){
  cin >> n >> m;
  for(int i = 1;i<=m;i++){
    int x,y,z;
    cin >>x >> y>> z;
    e[y].push_back({x,z});
    e[x].push_back({y,z});
  }
  long long sum = 0;
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>qe;
  qe.push({0,1});
  while(!qe.empty()){
    int u = qe.top().second;
    int uval = qe.top().first;
    qe.pop();
    if(vis[u])continue;
    vis[u] = 1;
    sum += uval;
    for(auto vv :e[u]){
      int v = vv.first, val = vv.second;
      qe.push({val,v});
    }
  }
  cout << sum << endl;
  return 0;
}
